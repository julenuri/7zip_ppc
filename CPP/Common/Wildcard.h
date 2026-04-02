// Common/Wildcard.h
// Patched for VC++ 4.0: VC4 eagerly instantiates ALL methods of a class
// template for every type used, even if those methods are never called.
// CObjectVector<CCensorNode>, CObjectVector<CItem> and CObjectVector<CPair>
// trigger instantiation of FindInSorted/AddToSorted which need operator==
// and operator<. Those operators are never actually called on these types,
// so we add dummy implementations that simply assert/return a safe value.

#ifndef __COMMON_WILDCARD_H
#define __COMMON_WILDCARD_H

#include "MyString.h"

int CompareFileNames(const UString &s1, const UString &s2);

void SplitPathToParts(const UString &path, UStringVector &pathParts);
void SplitPathToParts(const UString &path, UString &dirPrefix, UString &name);
UString ExtractDirPrefixFromPath(const UString &path);
UString ExtractFileNameFromPath(const UString &path);
bool DoesNameContainWildCard(const UString &path);
bool CompareWildCardWithName(const UString &mask, const UString &name);

namespace NWildcard {

struct CItem
{
  UStringVector PathParts;
  bool Recursive;
  bool ForFile;
  bool ForDir;
  bool CheckPath(const UStringVector &pathParts, bool isFile) const;

  // Dummy operators required by VC4 eager template instantiation.
  // CObjectVector<CItem> triggers FindInSorted/AddToSorted compilation
  // even though those methods are never actually called on CItem.
  bool operator==(const CItem &) const { return false; }
  bool operator<(const CItem &)  const { return false; }
};

class CCensorNode
{
  CCensorNode *Parent;
  bool CheckPathCurrent(bool include, const UStringVector &pathParts, bool isFile) const;
  void AddItemSimple(bool include, CItem &item);
  bool CheckPath(UStringVector &pathParts, bool isFile, bool &include) const;
public:
  CCensorNode(): Parent(0) { };
  CCensorNode(const UString &name, CCensorNode *parent): Name(name), Parent(parent) { };
  UString Name;
  CObjectVector<CCensorNode> SubNodes;
  CObjectVector<CItem> IncludeItems;
  CObjectVector<CItem> ExcludeItems;

  int FindSubNode(const UString &path) const;

  void AddItem(bool include, CItem &item);
  void AddItem(bool include, const UString &path, bool recursive, bool forFile, bool forDir);
  void AddItem2(bool include, const UString &path, bool recursive);

  bool NeedCheckSubDirs() const;
  bool AreThereIncludeItems() const;

  bool CheckPath(const UString &path, bool isFile, bool &include) const;
  bool CheckPath(const UString &path, bool isFile) const;

  bool CheckPathToRoot(bool include, UStringVector &pathParts, bool isFile) const;
  // bool CheckPathToRoot(const UString &path, bool isFile, bool include) const;
  void ExtendExclude(const CCensorNode &fromNodes);

  // Dummy operators required by VC4 eager template instantiation.
  bool operator==(const CCensorNode &) const { return false; }
  bool operator<(const CCensorNode &)  const { return false; }
};

struct CPair
{
  UString Prefix;
  CCensorNode Head;
  CPair(const UString &prefix): Prefix(prefix) { };

  // Dummy operators required by VC4 eager template instantiation.
  bool operator==(const CPair &) const { return false; }
  bool operator<(const CPair &)  const { return false; }
};

class CCensor
{
  int FindPrefix(const UString &prefix) const;
public:
  CObjectVector<CPair> Pairs;
  bool AllAreRelative() const
    { return (Pairs.Size() == 1 && Pairs.Front().Prefix.IsEmpty()); }
  void AddItem(bool include, const UString &path, bool recursive);
  bool CheckPath(const UString &path, bool isFile) const;
  void ExtendExclude();
};

}

#endif
