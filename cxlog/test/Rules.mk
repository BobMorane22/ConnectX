#*************************************************************************************************
#  This file is part of Connect X.
#
#  Connect X is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  Connect X is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with Connect X. If not, see <https://www.gnu.org/licenses/>.
#
#************************************************************************************************/
#
#*************************************************************************************************
# @file Rules.mk
# @date 2019
#
#************************************************************************************************/

### Updating current directory on stack
#
# Saves the variable "d" that holds the current directory on the stack, and sets it to the current
# directory given in "dir" (a parameter to the make fragment file).
#
# A textual "stack pointer" (sp) is used to keep track of the recursion depth of the include
# process. We "increment it" by adding a ".x" suffix to it.
#
sp := $(sp).x
dirstack_$(sp) := $(d)
d := $(dir)


### Local variables
#
# To the global variable "TGT_BIN", we add the "cxmodel" unit test executable.
#
# To the global variable "CLEAN", we add the files that the rules present here may create,
# i.e. the ones we want deleted by a "make clean" command.
#
TGTS_$(d) := $(d)/cxlogtests
OBJS_$(d) := $(d)/CSVLoggerChainLoggingTests.o \
             $(d)/CSVLoggerIncrementalLoggingTests.o \
             $(d)/CSVLoggerTests.o \
             $(d)/CSVLoggerUtil.o \
             $(d)/CSVMessageFormatterTests.o \
             $(d)/ISO8601TimestampFormatterTests.o \
             $(d)/StdLogTargetTests.o \
             $(d)/StringStreamLogTargetTests.o \
             $(d)/VerbosityLevelTests.o \
             cxunit/libcxunit.a \
             cxlog/libcxlog.a
             
# We include all the generated rules. These are created by GCC to make sure that
# changes to header files are recognized by make.
DEPS_$(d) := $(wildcard $(d)/*.d)

-include $(DEPS_$(d))

TGT_BIN := $(TGT_BIN) $(TGTS_$(d))

CLEAN := $(CLEAN) $(OBJS_$(d)) $(TGTS_$(d)) $(DEPS_$(d))


### Local rules
#
# Executable is compiled and linked.
#
$(TGTS_$(d)): CF_TGT := -I$(d)/../include -I$(d) -I.
$(TGTS_$(d)): LL_TGT := cxlog/libcxlog.a cxinv/libcxinv.a cxunit/libcxunit.a -lgtest -lgtest_main -lpthread

$(TGTS_$(d)): $(OBJS_$(d)) $(LL_TGT)
	@echo ~~~ Generating the cxlog unit tests executable ~~~
	$(LINK)
	$(SHELL) -c $@


### Restoring stack
#
# The stack pointer is "decremented" and the last current directory is restored.
#
-include $(DEPS_$(d))

d := $(dirstack_$(sp))
sp := $(basename $(sp))
