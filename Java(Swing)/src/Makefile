JFLAGS=-g
JC=javac
.SUFFIXES: .java .class
LIB_OUTDIR=../class

.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
	   MorseCodeGUI.java \
       Morse.java 

default: all

all: $(CLASSES:.java=.class) $(LIB_OUTDIR)

clean:
	$(RM) *.class
