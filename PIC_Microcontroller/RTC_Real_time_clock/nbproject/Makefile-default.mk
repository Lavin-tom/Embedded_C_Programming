#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/RTC_I2C.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/RTC_I2C.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=C:/Users/DELL/Downloads/PIC18F_Library/I2C.c C:/Users/DELL/Downloads/PIC18F_Library/LCD.c RTC_main.c ../PIC18F_Library/Keypad.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1937041488/I2C.p1 ${OBJECTDIR}/_ext/1937041488/LCD.p1 ${OBJECTDIR}/RTC_main.p1 ${OBJECTDIR}/_ext/1771299872/Keypad.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1937041488/I2C.p1.d ${OBJECTDIR}/_ext/1937041488/LCD.p1.d ${OBJECTDIR}/RTC_main.p1.d ${OBJECTDIR}/_ext/1771299872/Keypad.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1937041488/I2C.p1 ${OBJECTDIR}/_ext/1937041488/LCD.p1 ${OBJECTDIR}/RTC_main.p1 ${OBJECTDIR}/_ext/1771299872/Keypad.p1

# Source Files
SOURCEFILES=C:/Users/DELL/Downloads/PIC18F_Library/I2C.c C:/Users/DELL/Downloads/PIC18F_Library/LCD.c RTC_main.c ../PIC18F_Library/Keypad.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/RTC_I2C.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4520
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1937041488/I2C.p1: C:/Users/DELL/Downloads/PIC18F_Library/I2C.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1937041488" 
	@${RM} ${OBJECTDIR}/_ext/1937041488/I2C.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1937041488/I2C.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -mrom=4-7000 -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PIC18F_Library" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1937041488/I2C.p1 C:/Users/DELL/Downloads/PIC18F_Library/I2C.c 
	@-${MV} ${OBJECTDIR}/_ext/1937041488/I2C.d ${OBJECTDIR}/_ext/1937041488/I2C.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1937041488/I2C.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1937041488/LCD.p1: C:/Users/DELL/Downloads/PIC18F_Library/LCD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1937041488" 
	@${RM} ${OBJECTDIR}/_ext/1937041488/LCD.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1937041488/LCD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -mrom=4-7000 -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PIC18F_Library" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1937041488/LCD.p1 C:/Users/DELL/Downloads/PIC18F_Library/LCD.c 
	@-${MV} ${OBJECTDIR}/_ext/1937041488/LCD.d ${OBJECTDIR}/_ext/1937041488/LCD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1937041488/LCD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/RTC_main.p1: RTC_main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RTC_main.p1.d 
	@${RM} ${OBJECTDIR}/RTC_main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -mrom=4-7000 -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PIC18F_Library" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/RTC_main.p1 RTC_main.c 
	@-${MV} ${OBJECTDIR}/RTC_main.d ${OBJECTDIR}/RTC_main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/RTC_main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1771299872/Keypad.p1: ../PIC18F_Library/Keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1771299872" 
	@${RM} ${OBJECTDIR}/_ext/1771299872/Keypad.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1771299872/Keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -mrom=4-7000 -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PIC18F_Library" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1771299872/Keypad.p1 ../PIC18F_Library/Keypad.c 
	@-${MV} ${OBJECTDIR}/_ext/1771299872/Keypad.d ${OBJECTDIR}/_ext/1771299872/Keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1771299872/Keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/1937041488/I2C.p1: C:/Users/DELL/Downloads/PIC18F_Library/I2C.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1937041488" 
	@${RM} ${OBJECTDIR}/_ext/1937041488/I2C.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1937041488/I2C.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -mrom=4-7000 -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PIC18F_Library" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1937041488/I2C.p1 C:/Users/DELL/Downloads/PIC18F_Library/I2C.c 
	@-${MV} ${OBJECTDIR}/_ext/1937041488/I2C.d ${OBJECTDIR}/_ext/1937041488/I2C.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1937041488/I2C.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1937041488/LCD.p1: C:/Users/DELL/Downloads/PIC18F_Library/LCD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1937041488" 
	@${RM} ${OBJECTDIR}/_ext/1937041488/LCD.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1937041488/LCD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -mrom=4-7000 -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PIC18F_Library" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1937041488/LCD.p1 C:/Users/DELL/Downloads/PIC18F_Library/LCD.c 
	@-${MV} ${OBJECTDIR}/_ext/1937041488/LCD.d ${OBJECTDIR}/_ext/1937041488/LCD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1937041488/LCD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/RTC_main.p1: RTC_main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RTC_main.p1.d 
	@${RM} ${OBJECTDIR}/RTC_main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -mrom=4-7000 -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PIC18F_Library" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/RTC_main.p1 RTC_main.c 
	@-${MV} ${OBJECTDIR}/RTC_main.d ${OBJECTDIR}/RTC_main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/RTC_main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1771299872/Keypad.p1: ../PIC18F_Library/Keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1771299872" 
	@${RM} ${OBJECTDIR}/_ext/1771299872/Keypad.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1771299872/Keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -mrom=4-7000 -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PIC18F_Library" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1771299872/Keypad.p1 ../PIC18F_Library/Keypad.c 
	@-${MV} ${OBJECTDIR}/_ext/1771299872/Keypad.d ${OBJECTDIR}/_ext/1771299872/Keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1771299872/Keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/RTC_I2C.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/RTC_I2C.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -mrom=4-7000 -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PIC18F_Library" -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/RTC_I2C.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/RTC_I2C.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/RTC_I2C.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/RTC_I2C.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -mrom=4-7000 -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../PIC18F_Library" -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/RTC_I2C.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
