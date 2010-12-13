/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker-oscog.8 uuid: b336429e-652e-4551-8d38-a00ef67eaa61
   from
	UUIDPlugin VMMaker-oscog.8 uuid: b336429e-652e-4551-8d38-a00ef67eaa61
 */
static char __buildInfo[] = "UUIDPlugin VMMaker-oscog.8 uuid: b336429e-652e-4551-8d38-a00ef67eaa61 " __DATE__ ;




#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif
#include "UUIDPlugin.h"

#include "sqMemoryAccess.h"



/*** Constants ***/


/*** Function Prototypes ***/
static VirtualMachine * getInterpreter(void);
EXPORT(const char*) getModuleName(void);
static sqInt halt(void);
EXPORT(sqInt) initialiseModule(void);
static sqInt msg(char *s);
EXPORT(sqInt) primitiveMakeUUID(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
EXPORT(sqInt) shutdownModule(void);
static void sqAssert(sqInt aBool);


/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"UUIDPlugin VMMaker-oscog.8 (i)"
#else
	"UUIDPlugin VMMaker-oscog.8 (e)"
#endif
;



/*	Note: This is coded so that plugins can be run from Squeak. */

static VirtualMachine *
getInterpreter(void) {
	return interpreterProxy;
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*)
getModuleName(void) {
	return moduleName;
}

static sqInt
halt(void) {
	;
	return 0;
}

EXPORT(sqInt)
initialiseModule(void) {
	return sqUUIDInit();
}

static sqInt
msg(char *s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
	return 0;
}

EXPORT(sqInt)
primitiveMakeUUID(void) {
	sqInt oop;
	char*location;

	if (!((interpreterProxy->methodArgumentCount()) == 0)) {
		return interpreterProxy->primitiveFail();
	}
	oop = interpreterProxy->stackObjectValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->isBytes(oop))) {
		return interpreterProxy->primitiveFail();
	}
	if (!((interpreterProxy->byteSizeOf(oop)) == 16)) {
		return interpreterProxy->primitiveFail();
	}
	location = interpreterProxy->firstIndexableField(oop);
	return MakeUUID(location);
}


/*	Note: This is coded so that is can be run from Squeak. */

EXPORT(sqInt)
setInterpreter(struct VirtualMachine*anInterpreter) {
	sqInt ok;

	interpreterProxy = anInterpreter;
	ok = interpreterProxy->majorVersion() == VM_PROXY_MAJOR;
	if (ok == 0) {
		return 0;
	}
	ok = interpreterProxy->minorVersion() >= VM_PROXY_MINOR;
	return ok;
}

EXPORT(sqInt)
shutdownModule(void) {
	return sqUUIDShutdown();
}

static void
sqAssert(sqInt aBool) {
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

void* UUIDPlugin_exports[][3] = {
	{"UUIDPlugin", "getModuleName", (void*)getModuleName},
	{"UUIDPlugin", "initialiseModule", (void*)initialiseModule},
	{"UUIDPlugin", "primitiveMakeUUID", (void*)primitiveMakeUUID},
	{"UUIDPlugin", "setInterpreter", (void*)setInterpreter},
	{"UUIDPlugin", "shutdownModule", (void*)shutdownModule},
	{NULL, NULL, NULL}
};

#endif /* ifdef SQ_BUILTIN_PLUGIN */
