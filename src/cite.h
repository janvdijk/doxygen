/******************************************************************************
 *
 * Copyright (C) 2020 by Dimitri van Heesch
 * Based on a patch by David Munger
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 * Documents produced by Doxygen are derivative works derived from the
 * input used in their production; they are not affected by this license.
 *
 */

#ifndef CITE_H
#define CITE_H

#include <memory>
#include <map>

#include <qcstring.h>

class FTextStream;

/// Citation-related data.
struct CiteInfo
{
    virtual ~CiteInfo() {}
    virtual QCString label() const = 0;
    virtual QCString text() const = 0;
};

/**
 * @brief Citation manager class.
 * @details This class provides access do the database of bibliographic
 * references through the bibtex backend.
 */
class CitationManager
{
  public:
    static CitationManager &instance();

    /** Insert a citation identified by \a label into the database */
    void insert(const char *label);

    /** Return the citation info for a given \a label.
     *  Ownership of the info stays with the manager.
     */
    const CiteInfo *find(const char *label) const;

    /** Generate the citations page */
    void generatePage();

    /** clears the database */
    void clear();

    /** return TRUE if there are no citations.
     */
    bool isEmpty() const;

    /** writes the latex code for the standard bibliography
     *  section to text stream \a t
     */
    void writeLatexBibliography(FTextStream &t) const;

    const char *fileName() const;
    const char *anchorPrefix() const;

  private:
    /** Create the database, with an expected maximum of \a size entries */
    CitationManager();
    struct Private;
    std::unique_ptr<Private> p;
};

/**
 * @brief Dictionary class, used by dictval commands.
 * @details This class implements a dictionary that is populated with
 * the contents of the files that are listed in the DICTIONARY_FILES
 * configuration option. There is only one instance of this class,
 * which can be obtained with the static member instance. The object
 * is created when instance is called for the first time.
 */
class DictionaryManager
{
    using Entries = std::map<QCString,QCString>;
  public:
    static DictionaryManager &instance();

    /** Return the citation info for a given \a label, or 0 if not found. */
    const QCString *find(const char *label) const;

    void clear() { m_entries.clear(); }
    Entries::size_type size() { return m_entries.size(); }
  private:
    /** Create the database */
    DictionaryManager();
    Entries m_entries;
};



#endif // CITE_H
