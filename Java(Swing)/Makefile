JFLAGS=-g -Xlint
JC=javac
JRE=java
.SUFFIXES: .java .class
LIB_OUTDIR=class
CLASSPATH=.:$(LIB_OUTDIR)

.java.class:
	$(JC) $(JFLAGS) -cp $(CLASSPATH) $*.java

CLASSES = \
       Morse.java \
	   MorseCodeGUI.java

default: springutils all

springutils:
	$(JC) $(JFLAGS) src/layout/SpringUtilities.java -d $(LIB_OUTDIR)

all: $(CLASSES:.java=.class)

run:
	$(JRE) -cp $(CLASSPATH) MorseCodeGUI

clean:
	$(RM) *.class $(LIB_OUTDIR)/layout/*.class
