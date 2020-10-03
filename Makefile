################################### METADATA ###################################

# Contributors: roadelou
# Contacts: 
# Creation Date: 2020-10-03
# Language: Makefile

################################### ALIASES ####################################

# Root directory of the git repository
top = $(CURDIR)

# All source files
src = src/*.c
# All header files
head = include/*.h

# Flag to include all headers
include = -I$(top)/include/

# Flag to trigger compiler warnings
warn = -Wall -pedantic

# The name of the compiled executable
outdir = build
out = $(outdir)/base64.elf

################################### SPECIAL ####################################

.PHONY: clean

#################################### RULES #####################################

# The compilation flow here is rather straightforward.
$(out): $(src) $(head)
	mkdir -p $(outdir)
	clang $(warn) $(include) $(src) -o $(out)

clean:
	rm -f $(out)

##################################### EOF ######################################
