#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/CU1.o \
	${OBJECTDIR}/Categoria.o \
	${OBJECTDIR}/Comentario.o \
	${OBJECTDIR}/Controlador_Autenticacion.o \
	${OBJECTDIR}/Controlador_Desarrollador.o \
	${OBJECTDIR}/Controlador_Jugador.o \
	${OBJECTDIR}/DataComentario.o \
	${OBJECTDIR}/DataJuegos.o \
	${OBJECTDIR}/DataPartidas.o \
	${OBJECTDIR}/DataUsuario.o \
	${OBJECTDIR}/DataVideojuegoCU11.o \
	${OBJECTDIR}/DataVideojuegosCU5.o \
	${OBJECTDIR}/DtDate.o \
	${OBJECTDIR}/DtPartidasSinTerminar.o \
	${OBJECTDIR}/DtTime.o \
	${OBJECTDIR}/Estadistica.o \
	${OBJECTDIR}/Fabrica.o \
	${OBJECTDIR}/Historial.o \
	${OBJECTDIR}/ICollectible.o \
	${OBJECTDIR}/IDictionary.o \
	${OBJECTDIR}/IKey.o \
	${OBJECTDIR}/KeyInt.o \
	${OBJECTDIR}/KeyString.o \
	${OBJECTDIR}/ListDiccIterator.o \
	${OBJECTDIR}/ListDiccIteratorKey.o \
	${OBJECTDIR}/ListDiccIteratorObj.o \
	${OBJECTDIR}/Lista.o \
	${OBJECTDIR}/ListaDicc.o \
	${OBJECTDIR}/ListaIterator.o \
	${OBJECTDIR}/Nodo.o \
	${OBJECTDIR}/NodoDicc.o \
	${OBJECTDIR}/Par.o \
	${OBJECTDIR}/Partida.o \
	${OBJECTDIR}/Partida_1.o \
	${OBJECTDIR}/Suscripcion.o \
	${OBJECTDIR}/Usuario.o \
	${OBJECTDIR}/Videojuego.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/laboratorio_4.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/laboratorio_4.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/laboratorio_4 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/CU1.o: CU1.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CU1.o CU1.cpp

${OBJECTDIR}/Categoria.o: Categoria.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Categoria.o Categoria.cpp

${OBJECTDIR}/Comentario.o: Comentario.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Comentario.o Comentario.cpp

${OBJECTDIR}/Controlador_Autenticacion.o: Controlador_Autenticacion.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Controlador_Autenticacion.o Controlador_Autenticacion.cpp

${OBJECTDIR}/Controlador_Desarrollador.o: Controlador_Desarrollador.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Controlador_Desarrollador.o Controlador_Desarrollador.cpp

${OBJECTDIR}/Controlador_Jugador.o: Controlador_Jugador.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Controlador_Jugador.o Controlador_Jugador.cpp

${OBJECTDIR}/DataComentario.o: DataComentario.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataComentario.o DataComentario.cpp

${OBJECTDIR}/DataJuegos.o: DataJuegos.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataJuegos.o DataJuegos.cpp

${OBJECTDIR}/DataPartidas.o: DataPartidas.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataPartidas.o DataPartidas.cpp

${OBJECTDIR}/DataUsuario.o: DataUsuario.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataUsuario.o DataUsuario.cpp

${OBJECTDIR}/DataVideojuegoCU11.o: DataVideojuegoCU11.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataVideojuegoCU11.o DataVideojuegoCU11.cpp

${OBJECTDIR}/DataVideojuegosCU5.o: DataVideojuegosCU5.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataVideojuegosCU5.o DataVideojuegosCU5.cpp

${OBJECTDIR}/DtDate.o: DtDate.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtDate.o DtDate.cpp

${OBJECTDIR}/DtPartidasSinTerminar.o: DtPartidasSinTerminar.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtPartidasSinTerminar.o DtPartidasSinTerminar.cpp

${OBJECTDIR}/DtTime.o: DtTime.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtTime.o DtTime.cpp

${OBJECTDIR}/Estadistica.o: Estadistica.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Estadistica.o Estadistica.cpp

${OBJECTDIR}/Fabrica.o: Fabrica.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Fabrica.o Fabrica.cpp

${OBJECTDIR}/Historial.o: Historial.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Historial.o Historial.cpp

${OBJECTDIR}/ICollectible.o: ICollectible.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollectible.o ICollectible.cpp

${OBJECTDIR}/IDictionary.o: IDictionary.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IDictionary.o IDictionary.cpp

${OBJECTDIR}/IKey.o: IKey.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IKey.o IKey.cpp

${OBJECTDIR}/KeyInt.o: KeyInt.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/KeyInt.o KeyInt.cpp

${OBJECTDIR}/KeyString.o: KeyString.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/KeyString.o KeyString.cpp

${OBJECTDIR}/ListDiccIterator.o: ListDiccIterator.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListDiccIterator.o ListDiccIterator.cpp

${OBJECTDIR}/ListDiccIteratorKey.o: ListDiccIteratorKey.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListDiccIteratorKey.o ListDiccIteratorKey.cpp

${OBJECTDIR}/ListDiccIteratorObj.o: ListDiccIteratorObj.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListDiccIteratorObj.o ListDiccIteratorObj.cpp

${OBJECTDIR}/Lista.o: Lista.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Lista.o Lista.cpp

${OBJECTDIR}/ListaDicc.o: ListaDicc.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListaDicc.o ListaDicc.cpp

${OBJECTDIR}/ListaIterator.o: ListaIterator.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListaIterator.o ListaIterator.cpp

${OBJECTDIR}/Nodo.o: Nodo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Nodo.o Nodo.cpp

${OBJECTDIR}/NodoDicc.o: NodoDicc.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NodoDicc.o NodoDicc.cpp

${OBJECTDIR}/Par.o: Par.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Par.o Par.cpp

${OBJECTDIR}/Partida.o: Partida.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Partida.o Partida.cpp

${OBJECTDIR}/Partida_1.o: Partida_1.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Partida_1.o Partida_1.cpp

${OBJECTDIR}/Suscripcion.o: Suscripcion.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Suscripcion.o Suscripcion.cpp

${OBJECTDIR}/Usuario.o: Usuario.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Usuario.o Usuario.cpp

${OBJECTDIR}/Videojuego.o: Videojuego.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Videojuego.o Videojuego.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
