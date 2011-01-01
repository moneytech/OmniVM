/* Automatically generated by
	CCodeGenerator VMMaker-oscog.41 uuid: 096b8a29-e7e8-4cbf-b29c-0f096abbdd5c
 */


/*** Function Prototypes ***/
sqInt abortOffset(void);
void addCogMethodsToHeapMap(void);
sqInt bytecodePCForstartBcpcin(sqInt mcpc, sqInt startbcpc, CogBlockMethod *cogMethod);
sqInt canLinkToYoungClasses(void);
sqInt canMapBytecodePCsToNativePCs(void);
extern void (*ceCaptureCStackPointers)();
sqInt ceCPICMissreceiver(CogMethod *cPIC, sqInt receiver);
extern void (*ceEnterCogCodePopReceiverAndClassRegs)();
extern void (*ceEnterCogCodePopReceiverReg)();
sqInt ceSICMiss(sqInt receiver);
void checkAssertsEnabledInCogit(void);
sqInt checkIntegrityOfObjectReferencesInCode(sqInt fullGCFlag);
char * codeEntryFor(char *address);
char * codeEntryNameFor(char *address);
sqInt cogCodeBase(void);
sqInt cogCodeConstituents(void);
CogMethod * cogHomeMethod(CogBlockMethod *aCogMethod);
void cogitPostGCAction(void);
CogMethod * cogselector(sqInt aMethodObj, sqInt aSelectorOop);
void compactCogCompiledCode(void);
void enterCogCodePopReceiver(void);
void enterCogCodePopReceiverAndClassRegs(void);
CogBlockMethod * findEnclosingMethodForinHomeMethod(sqInt mcpc, CogMethod *cogMethod);
CogBlockMethod * findMethodForStartBcpcinHomeMethod(sqInt startbcpc, CogMethod *cogMethod);
sqInt genQuickReturnConst(void);
sqInt genQuickReturnInstVar(void);
sqInt genQuickReturnSelf(void);
void initializeCodeZoneFromupTo(sqInt startAddress, sqInt endAddress);
sqInt interpretOffset(void);
sqInt isSendReturnPC(sqInt retpc);
void linkSendAtintocheckedreceiver(sqInt callSiteReturnAddress, CogMethod *sendingMethod, CogMethod *targetMethod, sqInt checked, sqInt receiver);
sqInt mapForbcpcperformUntilarg(CogBlockMethod *cogMethod, sqInt startbcpc, sqInt (*functionSymbol)(char annotation, char *mcpc, sqInt bcpc, void *arg), void *arg);
void mapObjectReferencesInMachineCode(sqInt inFullGC);
void markAndTraceObjectsOrFreeMachineCode(sqInt inFullGC);
void markMethodAndReferents(CogBlockMethod *aCogMethod);
usqInt maxCogMethodAddress(void);
sqInt mcPCForstartBcpcin(sqInt bcpc, sqInt startbcpc, CogBlockMethod *cogMethod);
CogMethod * methodFor(void *address);
sqInt minCogMethodAddress(void);
sqInt mnuOffset(void);
sqInt numMethodsOfType(sqInt cogMethodType);
sqInt patchToOpenPICFornumArgsreceiver(sqInt selector, sqInt numArgs, sqInt receiver);
sqInt pcisWithinMethod(char *address, CogMethod *cogMethod);
void printCogMethodFor(void *address);
void printCogMethods(void);
void printCogMethodsOfType(sqInt cmType);
void printCogMethodsWithSelector(sqInt selectorOop);
void printTrampolineTable(void);
void recordCallOffsetInof(CogMethod *cogMethod, void *callLabelArg);
sqInt recordPrimTraceFunc(void);
void rewritePrimInvocationInto(CogMethod *cogMethod, void (*primFunctionPointer)(void));
void setBreakMethod(sqInt anObj);
void setPostCompileHook(void (*aFunction)(CogMethod *, void *));
void setSelectorOfto(CogMethod *cogMethod, sqInt aSelectorOop);
sqInt stackPageHeadroomBytes(void);
sqInt traceLinkedSendOffset(void);
void unlinkAllSends(void);
void unlinkSendsOf(sqInt selector);
void unlinkSendsToFree(void);
void unlinkSendsTo(CogMethod *targetMethod);
void voidCogCompiledCode(void);


/*** Global Variables ***/
sqInt blockNoContextSwitchOffset;
sqInt breakPC;
void * CFramePointer;
void * CStackPointer;
sqInt ceBaseFrameReturnTrampoline;
sqInt ceCannotResumeTrampoline;
void (*ceCaptureCStackPointers)(void);
sqInt ceCheckForInterruptTrampoline;
void (*ceEnterCogCodePopReceiverAndClassRegs)(void);
void (*ceEnterCogCodePopReceiverReg)(void);
unsigned long (*ceGetSP)(void);
sqInt ceReturnToInterpreterTrampoline;
unsigned long (*ceTryLockVMOwner)(void);
void (*ceUnlockVMOwner)(void);
sqInt cFramePointerInUse;
sqInt cmEntryOffset;
sqInt cmNoCheckEntryOffset;
unsigned long debugPrimCallStackOffset;
void (*realCEEnterCogCodePopReceiverAndClassRegs)(void);
void (*realCEEnterCogCodePopReceiverReg)(void);
int traceLinkedSends ;
sqInt traceStores;


/*** Macros ***/
#define ceBaseFrameReturnPC() ceBaseFrameReturnTrampoline
#define ceCannotResumePC() ((usqInt)ceCannotResumeTrampoline)
#define ceReturnToInterpreterPC() ((usqInt)ceReturnToInterpreterTrampoline)
#define entryOffset() cmEntryOffset
#define getCFramePointer() CFramePointer
#define getCStackPointer() CStackPointer
#define noCheckEntryOffset() cmNoCheckEntryOffset
#define noContextSwitchBlockEntryOffset() blockNoContextSwitchOffset
#define numRegArgs() 0
#define printOnTrace() (traceLinkedSends & 8)
#define recordEventTrace() (traceLinkedSends & 4)
#define recordPrimTrace() (traceLinkedSends & 2)
#define recordSendTrace() (traceLinkedSends & 1)
#define setCFramePointer(theFP) (CFramePointer = (void *)(theFP))
#define setCStackPointer(theSP) (CStackPointer = (void *)(theSP))
#define tryLockVMOwner() (ceTryLockVMOwner() != 0)
#define unlockVMOwner() ceUnlockVMOwner()

