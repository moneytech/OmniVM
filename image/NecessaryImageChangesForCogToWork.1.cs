'From Squeak4.1 of 17 April 2010 [latest update: #9957] on 26 May 2010 at 11:31:30 am'!!Float methodsFor: 'accessing' stamp: 'eem 4/19/2009 18:03'!at: index 	^self basicAt: index! !!Float methodsFor: 'accessing' stamp: 'eem 4/19/2009 18:03'!at: index put: value 	^self basicAt: index put: value! !!Float methodsFor: 'accessing' stamp: 'eem 4/20/2009 09:34'!basicAt: index	"Primitive. Assumes receiver is indexable. Answer the value of an 	indexable element in the receiver. Fail if the argument index is not an 	Integer or is out of bounds. Essential. Do not override in a subclass. See 	Object documentation whatIsAPrimitive.	This version of basicAt: is specifically for floats, answering the most significant	word for index 1 and the least significant word for index 2.  This alows the VM	to store floats in whatever order it chooses while it appears to the image that	they are always in big-endian/PowerPC order."	<primitive: 38 error: ec>	ec == nil ifTrue: "primitive not implemented; floats are in big-endian/PowerPC order."		[^super basicAt: index].	index isInteger ifTrue: [self errorSubscriptBounds: index].	index isNumber		ifTrue: [^self basicAt: index asInteger]		ifFalse: [self errorNonIntegerIndex]! !!Float methodsFor: 'accessing' stamp: 'eem 4/20/2009 09:35'!basicAt: index put: value	"Primitive. Assumes receiver is indexable. Store the second argument 	value in the indexable element of the receiver indicated by index. Fail 	if the index is not an Integer or is out of bounds. Or fail if the value is 	not of the right type for this kind of collection. Answer the value that 	was stored. Essential. Do not override in a subclass. See Object 	documentation whatIsAPrimitive.	This version of basicAt: is specifically for floats, answering the most significant	word for index 1 and the least significant word for index 2.  This alows the VM	to store floats in whatever order it chooses while it appears to the image that	they are always in big-endian/PowerPC order."	<primitive: 39 error: ec>	ec == nil ifTrue: "primitive not implemented; floats are in big-endian/PowerPC order."		[^super basicAt: index put: value].	index isInteger		ifTrue: [(index >= 1 and: [index <= self size])					ifTrue: [self errorImproperStore]					ifFalse: [self errorSubscriptBounds: index]].	index isNumber		ifTrue: [^self basicAt: index asInteger put: value]		ifFalse: [self errorNonIntegerIndex]! !!SmalltalkImage methodsFor: 'special objects' stamp: 'eem 5/26/2010 11:28'!recreateSpecialObjectsArray	"Smalltalk recreateSpecialObjectsArray"		"To external package developers:	**** DO NOT OVERRIDE THIS METHOD.  *****	If you are writing a plugin and need additional special object(s) for your own use, 	use addGCRoot() function and use own, separate special objects registry "		"The Special Objects Array is an array of objects used by the Squeak virtual machine.	 Its contents are critical and accesses to it by the VM are unchecked, so don't even	 think of playing here unless you know what you are doing."	| newArray |	newArray := Array new: 55.	"Nil false and true get used throughout the interpreter"	newArray at: 1 put: nil.	newArray at: 2 put: false.	newArray at: 3 put: true.	"This association holds the active process (a ProcessScheduler)"	newArray at: 4 put: (self associationAt: #Processor).	"Numerous classes below used for type checking and instantiation"	newArray at: 5 put: Bitmap.	newArray at: 6 put: SmallInteger.	newArray at: 7 put: ByteString.	newArray at: 8 put: Array.	newArray at: 9 put: Smalltalk.	newArray at: 10 put: Float.	newArray at: 11 put: MethodContext.	newArray at: 12 put: BlockContext.	newArray at: 13 put: Point.	newArray at: 14 put: LargePositiveInteger.	newArray at: 15 put: Display.	newArray at: 16 put: Message.	newArray at: 17 put: CompiledMethod.	newArray at: 18 put: (self specialObjectsArray at: 18).	"(low space Semaphore)"	newArray at: 19 put: Semaphore.	newArray at: 20 put: Character.	newArray at: 21 put: #doesNotUnderstand:.	newArray at: 22 put: #cannotReturn:.	newArray at: 23 put: nil. "This is the process signalling low space."	"An array of the 32 selectors that are compiled as special bytecodes,	 paired alternately with the number of arguments each takes."	newArray at: 24 put: #(	#+ 1 #- 1 #< 1 #> 1 #<= 1 #>= 1 #= 1 #~= 1							#* 1 #/ 1 #\\ 1 #@ 1 #bitShift: 1 #// 1 #bitAnd: 1 #bitOr: 1							#at: 1 #at:put: 2 #size 0 #next 0 #nextPut: 1 #atEnd 0 #== 1 #class 0							#blockCopy: 1 #value 0 #value: 1 #do: 1 #new 0 #new: 1 #x 0 #y 0 ).	"An array of the 255 Characters in ascii order.	 Cog inlines table into machine code at: prim so do not regenerate it."	newArray at: 25 put: (self specialObjectsArray at: 25).	newArray at: 26 put: #mustBeBoolean.	newArray at: 27 put: ByteArray.	newArray at: 28 put: Process.	"An array of up to 31 classes whose instances will have compact headers"	newArray at: 29 put: self compactClassesArray.	newArray at: 30 put: (self specialObjectsArray at: 30).	"(delay Semaphore)"	newArray at: 31 put: (self specialObjectsArray at: 31).	"(user interrupt Semaphore)"	"Prototype instances that can be copied for fast initialization"	newArray at: 32 put: (Float new: 2).	newArray at: 33 put: (LargePositiveInteger new: 4).	newArray at: 34 put: Point new.	newArray at: 35 put: #cannotInterpret:.	"Note: This must be fixed once we start using context prototypes (yeah, right)"	"(MethodContext new: CompiledMethod fullFrameSize)."	newArray at: 36 put: (self specialObjectsArray at: 36). "Is the prototype MethodContext (unused by the VM)"	newArray at: 37 put: BlockClosure.	"(BlockContext new: CompiledMethod fullFrameSize)."	newArray at: 38 put: (self specialObjectsArray at: 38). "Is the prototype BlockContext (unused by the VM)"	"array of objects referred to by external code"	newArray at: 39 put: (self specialObjectsArray at: 39).	"preserve external semaphores"	newArray at: 40 put: PseudoContext. "Obsolete.  Reserved for Mutex in Cog VMs"	newArray at: 41 put: TranslatedMethod. "Obsolete.  Reserved for a LinkedList instance for overlapped calls in CogMT"	"finalization Semaphore"	newArray at: 42 put: ((self specialObjectsArray at: 42) ifNil: [Semaphore new]).	newArray at: 43 put: LargeNegativeInteger.	"External objects for callout.	 Note: Written so that one can actually completely remove the FFI."	newArray at: 44 put: (self at: #ExternalAddress ifAbsent: []).	newArray at: 45 put: (self at: #ExternalStructure ifAbsent: []).	newArray at: 46 put: (self at: #ExternalData ifAbsent: []).	newArray at: 47 put: (self at: #ExternalFunction ifAbsent: []).	newArray at: 48 put: (self at: #ExternalLibrary ifAbsent: []).	newArray at: 49 put: #aboutToReturn:through:.	newArray at: 50 put: #run:with:in:.	"51 reserved for immutability message"	"newArray at: 51 put: #attemptToAssign:withIndex:."	newArray at: 52 put: #(nil "nil => generic error" #'bad receiver'							#'bad argument' #'bad index'							#'bad number of arguments'							#'inappropriate operation'  #'unsupported operation'							#'no modification' #'insufficient object memory'							#'insufficient C memory' #'not found' #'bad method'							#'internal error in named primitive machinery'							#'object may move').	"53 to 55 are for Alien"	newArray at: 53 put: (self at: #Alien ifAbsent: []).	newArray at: 54 put: #invokeCallback:stack:registers:jmpbuf:.	newArray at: 55 put: (self at: #UnsafeAlien ifAbsent: []).		"Now replace the interpreter's reference in one atomic operation"	self specialObjectsArray become: newArray	! !LargePositiveInteger removeSelector: #=!LargePositiveInteger removeSelector: #bitAnd:!LargePositiveInteger removeSelector: #bitOr:!LargePositiveInteger removeSelector: #bitShift:!LargePositiveInteger removeSelector: #bitXor:!LargePositiveInteger removeSelector: #'~='!