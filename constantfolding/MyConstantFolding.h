#ifndef LLVM_TRANSFORMS_UTILS_MYCONSTANTFOLDING_H
#define LLVM_TRANSFORMS_UTILS_MYCONSTANTFOLDING_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class MyConstantFoldingPass : public PassInfoMixin<MyConstantFoldingPass> {
public:
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);
};

} // namespace llvm

#endif // LLVM_TRANSFORMS_UTILS_MYCONSTANTFOLDING_H
