// UpdatePair.h

#ifndef __UPDATE_PAIR_H
#define __UPDATE_PAIR_H

#include "DirItem.h"
#include "UpdateAction.h"

#include "../../Archive/IArchive.h"

struct CUpdatePair
{
  NUpdateArchive::NPairState::EEnum State;
  int ArcIndex;
  int DirIndex;
  CUpdatePair(): ArcIndex(-1), DirIndex(-1) {}
  // Operadores Dummy para VC4 siguiendo plantilla de creación de instancias
  bool operator==(const CUpdatePair &) const { return false; }
  bool operator<(const CUpdatePair &)  const { return false; }
};

void GetUpdatePairInfoList(
    const CDirItems &dirItems,
    const CObjectVector<CArcItem> &arcItems,
    NFileTimeType::EEnum fileTimeType,
    CRecordVector<CUpdatePair> &updatePairs);

#endif
