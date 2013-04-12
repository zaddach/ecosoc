#ifndef __PADRIVER_H__
#define __PADRIVER_H__

#include <sstream>
#include <unistd.h>
#include <ios>
#include <fstream>
#include <string>
#include <iostream>

#include "llvm/Use.h"
#include "llvm/Pass.h"
#include "llvm/Module.h"
#include "llvm/Operator.h"
#include "llvm/Instructions.h"
#include "llvm/InstrTypes.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/CallSite.h"
#include "llvm/Support/Debug.h"
#include "llvm/ADT/Statistic.h"

#include "PointerAnalysis.h"

using namespace llvm;

class PADriver : public ModulePass {
        public:
        // +++++ FIELDS +++++ //
        // Used to assign a int ID to Values and store names
        int currInd;
        int nextMemoryBlock;
        std::map<Value*, int> value2int;
        std::map<int, Value*> int2value;

        std::map<Value*, int> valMap;
        std::map<Value*, std::vector<int> > valMem;
        std::map<int, std::string> nameMap;

        std::map<Value*, std::vector<int> > memoryBlock;
        std::map<int, std::vector<int> > memoryBlock2;
        std::map<Value*, std::vector<Value*> > phiValues;
        std::map<Value*, std::vector<std::vector<int> > > memoryBlocks;
        unsigned int numInst;

        static char ID;
        PointerAnalysis* pointerAnalysis;

        PADriver();

        // +++++ METHODS +++++ //

        bool runOnModule(Module &M);
        int Value2Int(Value* v);
        int getNewMem(std::string name);
        int getNewInt(); 
        int getNewMemoryBlock();
        void handleNestedStructs(const Type *Ty, int parent);
        void handleAlloca(Instruction *I);
        void handleGlobalVariable(GlobalVariable *G);
        void handleGetElementPtr(Instruction *I);
        //Value* Int2Value(int);
        virtual void print(raw_ostream& O, const Module* M) const;
        std::string intToStr(int v);
        void process_mem_usage(double& vm_usage, double& resident_set);
        void addConstraints(Function &F);
        void matchFormalWithActualParameters(Function &F);
        void matchReturnValueWithReturnVariable(Function &F);

};

#endif

