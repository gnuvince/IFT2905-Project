#############################################################################
# Makefile for building: projet
# Generated by qmake (2.01a) (Qt 4.7.2) on: Thu Apr 28 12:11:28 2011
# Project:  projet.pro
# Template: app
# Command: /usr/bin/qmake -spec /usr/share/qt/mkspecs/linux-g++-64 QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger -o Makefile projet.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DPATH="\"/home/vince/universite/H11/IFT2905/Projet\"" -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -march=x86-64 -mtune=generic -O2 -pipe -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -march=x86-64 -mtune=generic -O2 -pipe -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt/mkspecs/linux-g++-64 -I. -I/usr/include/QtCore -I/usr/include/QtGui -I/usr/include -I. -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,--hash-style=gnu -Wl,--as-needed -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = geoposition.cpp \
		geopositiondelegate.cpp \
		main.cpp \
		mainwindow.cpp \
		manote.cpp \
		note.cpp \
		notemodel.cpp \
		reservation.cpp \
		reservationmodel.cpp \
		simulateur.cpp \
		station.cpp \
		stationmodel.cpp \
		usager.cpp \
		usagermodel.cpp \
		vehicule.cpp \
		vehiculemodel.cpp \
		reservationproxymodel.cpp \
		robot.cpp \
		cartescene.cpp \
		carteelements.cpp \
		cartewidget.cpp \
		userinterface.cpp \
		pages/page.cpp \
		pages/mainmenupage.cpp \
		pages/findstationpage.cpp \
		pages/selectpositionpage.cpp \
		pages/selectstationpage.cpp \
		pages/selecttimepage.cpp \
		pages/selectcarpage.cpp \
		pages/confirmpage.cpp \
		stationsortproxy.cpp \
		pages/commentspage.cpp \
		pages/unexpectedpage.cpp \
		pages/bookingspage.cpp \
		pages/mymessagespage.cpp \
		pages/writecommentpage.cpp \
		pages/infostationpage.cpp \
		vehiculefilterproxy.cpp \
		pages/infocarpage.cpp \
		reservationfilterproxy.cpp moc_geopositiondelegate.cpp \
		moc_mainwindow.cpp \
		moc_note.cpp \
		moc_notemodel.cpp \
		moc_reservation.cpp \
		moc_reservationmodel.cpp \
		moc_simulateur.cpp \
		moc_station.cpp \
		moc_stationmodel.cpp \
		moc_usager.cpp \
		moc_usagermodel.cpp \
		moc_vehicule.cpp \
		moc_vehiculemodel.cpp \
		moc_robot.cpp \
		moc_reservationproxymodel.cpp \
		moc_cartescene.cpp \
		moc_carteelements.cpp \
		moc_cartewidget.cpp \
		moc_userinterface.cpp \
		moc_page.cpp \
		moc_mainmenupage.cpp \
		moc_findstationpage.cpp \
		moc_selectpositionpage.cpp \
		moc_selectstationpage.cpp \
		moc_selecttimepage.cpp \
		moc_selectcarpage.cpp \
		moc_confirmpage.cpp \
		moc_stationsortproxy.cpp \
		moc_commentspage.cpp \
		moc_unexpectedpage.cpp \
		moc_bookingspage.cpp \
		moc_mymessagespage.cpp \
		moc_writecommentpage.cpp \
		moc_infostationpage.cpp \
		moc_vehiculefilterproxy.cpp \
		moc_infocarpage.cpp \
		moc_reservationfilterproxy.cpp \
		qrc_icones.cpp
OBJECTS       = geoposition.o \
		geopositiondelegate.o \
		main.o \
		mainwindow.o \
		manote.o \
		note.o \
		notemodel.o \
		reservation.o \
		reservationmodel.o \
		simulateur.o \
		station.o \
		stationmodel.o \
		usager.o \
		usagermodel.o \
		vehicule.o \
		vehiculemodel.o \
		reservationproxymodel.o \
		robot.o \
		cartescene.o \
		carteelements.o \
		cartewidget.o \
		userinterface.o \
		page.o \
		mainmenupage.o \
		findstationpage.o \
		selectpositionpage.o \
		selectstationpage.o \
		selecttimepage.o \
		selectcarpage.o \
		confirmpage.o \
		stationsortproxy.o \
		commentspage.o \
		unexpectedpage.o \
		bookingspage.o \
		mymessagespage.o \
		writecommentpage.o \
		infostationpage.o \
		vehiculefilterproxy.o \
		infocarpage.o \
		reservationfilterproxy.o \
		moc_geopositiondelegate.o \
		moc_mainwindow.o \
		moc_note.o \
		moc_notemodel.o \
		moc_reservation.o \
		moc_reservationmodel.o \
		moc_simulateur.o \
		moc_station.o \
		moc_stationmodel.o \
		moc_usager.o \
		moc_usagermodel.o \
		moc_vehicule.o \
		moc_vehiculemodel.o \
		moc_robot.o \
		moc_reservationproxymodel.o \
		moc_cartescene.o \
		moc_carteelements.o \
		moc_cartewidget.o \
		moc_userinterface.o \
		moc_page.o \
		moc_mainmenupage.o \
		moc_findstationpage.o \
		moc_selectpositionpage.o \
		moc_selectstationpage.o \
		moc_selecttimepage.o \
		moc_selectcarpage.o \
		moc_confirmpage.o \
		moc_stationsortproxy.o \
		moc_commentspage.o \
		moc_unexpectedpage.o \
		moc_bookingspage.o \
		moc_mymessagespage.o \
		moc_writecommentpage.o \
		moc_infostationpage.o \
		moc_vehiculefilterproxy.o \
		moc_infocarpage.o \
		moc_reservationfilterproxy.o \
		qrc_icones.o
DIST          = /usr/share/qt/mkspecs/common/g++.conf \
		/usr/share/qt/mkspecs/common/unix.conf \
		/usr/share/qt/mkspecs/common/linux.conf \
		/usr/share/qt/mkspecs/qconfig.pri \
		/usr/share/qt/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt/mkspecs/features/qt_functions.prf \
		/usr/share/qt/mkspecs/features/qt_config.prf \
		/usr/share/qt/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt/mkspecs/features/default_pre.prf \
		/usr/share/qt/mkspecs/features/release.prf \
		/usr/share/qt/mkspecs/features/default_post.prf \
		/usr/share/qt/mkspecs/features/warn_on.prf \
		/usr/share/qt/mkspecs/features/qt.prf \
		/usr/share/qt/mkspecs/features/unix/thread.prf \
		/usr/share/qt/mkspecs/features/moc.prf \
		/usr/share/qt/mkspecs/features/resources.prf \
		/usr/share/qt/mkspecs/features/uic.prf \
		/usr/share/qt/mkspecs/features/yacc.prf \
		/usr/share/qt/mkspecs/features/lex.prf \
		/usr/share/qt/mkspecs/features/include_source_dir.prf \
		projet.pro
QMAKE_TARGET  = projet
DESTDIR       = 
TARGET        = projet

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h ui_cartewidget.h ui_userinterface.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: projet.pro  /usr/share/qt/mkspecs/linux-g++-64/qmake.conf /usr/share/qt/mkspecs/common/g++.conf \
		/usr/share/qt/mkspecs/common/unix.conf \
		/usr/share/qt/mkspecs/common/linux.conf \
		/usr/share/qt/mkspecs/qconfig.pri \
		/usr/share/qt/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt/mkspecs/features/qt_functions.prf \
		/usr/share/qt/mkspecs/features/qt_config.prf \
		/usr/share/qt/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt/mkspecs/features/default_pre.prf \
		/usr/share/qt/mkspecs/features/release.prf \
		/usr/share/qt/mkspecs/features/default_post.prf \
		/usr/share/qt/mkspecs/features/warn_on.prf \
		/usr/share/qt/mkspecs/features/qt.prf \
		/usr/share/qt/mkspecs/features/unix/thread.prf \
		/usr/share/qt/mkspecs/features/moc.prf \
		/usr/share/qt/mkspecs/features/resources.prf \
		/usr/share/qt/mkspecs/features/uic.prf \
		/usr/share/qt/mkspecs/features/yacc.prf \
		/usr/share/qt/mkspecs/features/lex.prf \
		/usr/share/qt/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt/mkspecs/linux-g++-64 QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger -o Makefile projet.pro
/usr/share/qt/mkspecs/common/g++.conf:
/usr/share/qt/mkspecs/common/unix.conf:
/usr/share/qt/mkspecs/common/linux.conf:
/usr/share/qt/mkspecs/qconfig.pri:
/usr/share/qt/mkspecs/modules/qt_phonon.pri:
/usr/share/qt/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt/mkspecs/features/qt_functions.prf:
/usr/share/qt/mkspecs/features/qt_config.prf:
/usr/share/qt/mkspecs/features/exclusive_builds.prf:
/usr/share/qt/mkspecs/features/default_pre.prf:
/usr/share/qt/mkspecs/features/release.prf:
/usr/share/qt/mkspecs/features/default_post.prf:
/usr/share/qt/mkspecs/features/warn_on.prf:
/usr/share/qt/mkspecs/features/qt.prf:
/usr/share/qt/mkspecs/features/unix/thread.prf:
/usr/share/qt/mkspecs/features/moc.prf:
/usr/share/qt/mkspecs/features/resources.prf:
/usr/share/qt/mkspecs/features/uic.prf:
/usr/share/qt/mkspecs/features/yacc.prf:
/usr/share/qt/mkspecs/features/lex.prf:
/usr/share/qt/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt/mkspecs/linux-g++-64 QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger -o Makefile projet.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/projet1.0.0 || $(MKDIR) .tmp/projet1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/projet1.0.0/ && $(COPY_FILE) --parents geoposition.h geopositiondelegate.h mainwindow.h manote.h note.h notemodel.h reservation.h reservationmodel.h simulateur.h station.h stationmodel.h usager.h usagermodel.h vehicule.h vehiculemodel.h robot.h reservationproxymodel.h cartescene.h carteelements.h cartewidget.h userinterface.h pages/page.h pages/mainmenupage.h pages/findstationpage.h pages/selectpositionpage.h pages/selectstationpage.h pages/selecttimepage.h pages/selectcarpage.h pages/confirmpage.h stationsortproxy.h pages/commentspage.h pages/unexpectedpage.h pages/bookingspage.h pages/mymessagespage.h pages/writecommentpage.h pages/infostationpage.h vehiculefilterproxy.h pages/infocarpage.h reservationfilterproxy.h .tmp/projet1.0.0/ && $(COPY_FILE) --parents icones.qrc .tmp/projet1.0.0/ && $(COPY_FILE) --parents geoposition.cpp geopositiondelegate.cpp main.cpp mainwindow.cpp manote.cpp note.cpp notemodel.cpp reservation.cpp reservationmodel.cpp simulateur.cpp station.cpp stationmodel.cpp usager.cpp usagermodel.cpp vehicule.cpp vehiculemodel.cpp reservationproxymodel.cpp robot.cpp cartescene.cpp carteelements.cpp cartewidget.cpp userinterface.cpp pages/page.cpp pages/mainmenupage.cpp pages/findstationpage.cpp pages/selectpositionpage.cpp pages/selectstationpage.cpp pages/selecttimepage.cpp pages/selectcarpage.cpp pages/confirmpage.cpp stationsortproxy.cpp pages/commentspage.cpp pages/unexpectedpage.cpp pages/bookingspage.cpp pages/mymessagespage.cpp pages/writecommentpage.cpp pages/infostationpage.cpp vehiculefilterproxy.cpp pages/infocarpage.cpp reservationfilterproxy.cpp .tmp/projet1.0.0/ && $(COPY_FILE) --parents mainwindow.ui cartewidget.ui userinterface.ui .tmp/projet1.0.0/ && (cd `dirname .tmp/projet1.0.0` && $(TAR) projet1.0.0.tar projet1.0.0 && $(COMPRESS) projet1.0.0.tar) && $(MOVE) `dirname .tmp/projet1.0.0`/projet1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/projet1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


tar:
	tar -zcf projet.tar.gz geoposition.cpp geopositiondelegate.cpp main.cpp mainwindow.cpp manote.cpp note.cpp notemodel.cpp reservation.cpp reservationmodel.cpp simulateur.cpp station.cpp stationmodel.cpp usager.cpp usagermodel.cpp vehicule.cpp vehiculemodel.cpp reservationproxymodel.cpp robot.cpp cartescene.cpp carteelements.cpp cartewidget.cpp userinterface.cpp pages/page.cpp pages/mainmenupage.cpp pages/findstationpage.cpp pages/selectpositionpage.cpp pages/selectstationpage.cpp pages/selecttimepage.cpp pages/selectcarpage.cpp pages/confirmpage.cpp stationsortproxy.cpp pages/commentspage.cpp pages/unexpectedpage.cpp pages/bookingspage.cpp pages/mymessagespage.cpp pages/writecommentpage.cpp pages/infostationpage.cpp vehiculefilterproxy.cpp pages/infocarpage.cpp reservationfilterproxy.cpp geoposition.h geopositiondelegate.h mainwindow.h manote.h note.h notemodel.h reservation.h reservationmodel.h simulateur.h station.h stationmodel.h usager.h usagermodel.h vehicule.h vehiculemodel.h robot.h reservationproxymodel.h cartescene.h carteelements.h cartewidget.h userinterface.h pages/page.h pages/mainmenupage.h pages/findstationpage.h pages/selectpositionpage.h pages/selectstationpage.h pages/selecttimepage.h pages/selectcarpage.h pages/confirmpage.h stationsortproxy.h pages/commentspage.h pages/unexpectedpage.h pages/bookingspage.h pages/mymessagespage.h pages/writecommentpage.h pages/infostationpage.h vehiculefilterproxy.h pages/infocarpage.h reservationfilterproxy.h mainwindow.ui cartewidget.ui userinterface.ui icones.qrc data/xml/map_montreal.osm data/xml/*.xml data/images/icons/*.png data/images/stations/*.jpg data/images/stations/*.gif data/images/vehicules/*.png projet.pro

check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_geopositiondelegate.cpp moc_mainwindow.cpp moc_note.cpp moc_notemodel.cpp moc_reservation.cpp moc_reservationmodel.cpp moc_simulateur.cpp moc_station.cpp moc_stationmodel.cpp moc_usager.cpp moc_usagermodel.cpp moc_vehicule.cpp moc_vehiculemodel.cpp moc_robot.cpp moc_reservationproxymodel.cpp moc_cartescene.cpp moc_carteelements.cpp moc_cartewidget.cpp moc_userinterface.cpp moc_page.cpp moc_mainmenupage.cpp moc_findstationpage.cpp moc_selectpositionpage.cpp moc_selectstationpage.cpp moc_selecttimepage.cpp moc_selectcarpage.cpp moc_confirmpage.cpp moc_stationsortproxy.cpp moc_commentspage.cpp moc_unexpectedpage.cpp moc_bookingspage.cpp moc_mymessagespage.cpp moc_writecommentpage.cpp moc_infostationpage.cpp moc_vehiculefilterproxy.cpp moc_infocarpage.cpp moc_reservationfilterproxy.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_geopositiondelegate.cpp moc_mainwindow.cpp moc_note.cpp moc_notemodel.cpp moc_reservation.cpp moc_reservationmodel.cpp moc_simulateur.cpp moc_station.cpp moc_stationmodel.cpp moc_usager.cpp moc_usagermodel.cpp moc_vehicule.cpp moc_vehiculemodel.cpp moc_robot.cpp moc_reservationproxymodel.cpp moc_cartescene.cpp moc_carteelements.cpp moc_cartewidget.cpp moc_userinterface.cpp moc_page.cpp moc_mainmenupage.cpp moc_findstationpage.cpp moc_selectpositionpage.cpp moc_selectstationpage.cpp moc_selecttimepage.cpp moc_selectcarpage.cpp moc_confirmpage.cpp moc_stationsortproxy.cpp moc_commentspage.cpp moc_unexpectedpage.cpp moc_bookingspage.cpp moc_mymessagespage.cpp moc_writecommentpage.cpp moc_infostationpage.cpp moc_vehiculefilterproxy.cpp moc_infocarpage.cpp moc_reservationfilterproxy.cpp
moc_geopositiondelegate.cpp: geopositiondelegate.h
	/usr/bin/moc $(DEFINES) $(INCPATH) geopositiondelegate.h -o moc_geopositiondelegate.cpp

moc_mainwindow.cpp: mainwindow.h
	/usr/bin/moc $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_note.cpp: note.h
	/usr/bin/moc $(DEFINES) $(INCPATH) note.h -o moc_note.cpp

moc_notemodel.cpp: note.h \
		notemodel.h
	/usr/bin/moc $(DEFINES) $(INCPATH) notemodel.h -o moc_notemodel.cpp

moc_reservation.cpp: reservation.h
	/usr/bin/moc $(DEFINES) $(INCPATH) reservation.h -o moc_reservation.cpp

moc_reservationmodel.cpp: reservation.h \
		station.h \
		geoposition.h \
		vehicule.h \
		reservationmodel.h
	/usr/bin/moc $(DEFINES) $(INCPATH) reservationmodel.h -o moc_reservationmodel.cpp

moc_simulateur.cpp: simulateur.h
	/usr/bin/moc $(DEFINES) $(INCPATH) simulateur.h -o moc_simulateur.cpp

moc_station.cpp: geoposition.h \
		station.h
	/usr/bin/moc $(DEFINES) $(INCPATH) station.h -o moc_station.cpp

moc_stationmodel.cpp: station.h \
		geoposition.h \
		stationmodel.h
	/usr/bin/moc $(DEFINES) $(INCPATH) stationmodel.h -o moc_stationmodel.cpp

moc_usager.cpp: geoposition.h \
		usager.h
	/usr/bin/moc $(DEFINES) $(INCPATH) usager.h -o moc_usager.cpp

moc_usagermodel.cpp: usager.h \
		geoposition.h \
		usagermodel.h
	/usr/bin/moc $(DEFINES) $(INCPATH) usagermodel.h -o moc_usagermodel.cpp

moc_vehicule.cpp: vehicule.h
	/usr/bin/moc $(DEFINES) $(INCPATH) vehicule.h -o moc_vehicule.cpp

moc_vehiculemodel.cpp: vehicule.h \
		vehiculemodel.h
	/usr/bin/moc $(DEFINES) $(INCPATH) vehiculemodel.h -o moc_vehiculemodel.cpp

moc_robot.cpp: robot.h
	/usr/bin/moc $(DEFINES) $(INCPATH) robot.h -o moc_robot.cpp

moc_reservationproxymodel.cpp: reservationmodel.h \
		reservation.h \
		station.h \
		geoposition.h \
		vehicule.h \
		reservationproxymodel.h
	/usr/bin/moc $(DEFINES) $(INCPATH) reservationproxymodel.h -o moc_reservationproxymodel.cpp

moc_cartescene.cpp: carteelements.h \
		geoposition.h \
		cartescene.h
	/usr/bin/moc $(DEFINES) $(INCPATH) cartescene.h -o moc_cartescene.cpp

moc_carteelements.cpp: carteelements.h
	/usr/bin/moc $(DEFINES) $(INCPATH) carteelements.h -o moc_carteelements.cpp

moc_cartewidget.cpp: geoposition.h \
		cartewidget.h
	/usr/bin/moc $(DEFINES) $(INCPATH) cartewidget.h -o moc_cartewidget.cpp

moc_userinterface.cpp: pages/page.h \
		station.h \
		geoposition.h \
		stationmodel.h \
		stationsortproxy.h \
		vehiculemodel.h \
		vehicule.h \
		usagermodel.h \
		usager.h \
		vehiculefilterproxy.h \
		reservation.h \
		reservationmodel.h \
		reservationfilterproxy.h \
		userinterface.h
	/usr/bin/moc $(DEFINES) $(INCPATH) userinterface.h -o moc_userinterface.cpp

moc_page.cpp: pages/page.h
	/usr/bin/moc $(DEFINES) $(INCPATH) pages/page.h -o moc_page.cpp

moc_mainmenupage.cpp: pages/page.h \
		pages/mainmenupage.h
	/usr/bin/moc $(DEFINES) $(INCPATH) pages/mainmenupage.h -o moc_mainmenupage.cpp

moc_findstationpage.cpp: pages/page.h \
		pages/findstationpage.h
	/usr/bin/moc $(DEFINES) $(INCPATH) pages/findstationpage.h -o moc_findstationpage.cpp

moc_selectpositionpage.cpp: pages/page.h \
		geoposition.h \
		cartewidget.h \
		pages/selectpositionpage.h
	/usr/bin/moc $(DEFINES) $(INCPATH) pages/selectpositionpage.h -o moc_selectpositionpage.cpp

moc_selectstationpage.cpp: stationsortproxy.h \
		station.h \
		geoposition.h \
		pages/page.h \
		pages/selectstationpage.h
	/usr/bin/moc $(DEFINES) $(INCPATH) pages/selectstationpage.h -o moc_selectstationpage.cpp

moc_selecttimepage.cpp: pages/page.h \
		pages/selecttimepage.h
	/usr/bin/moc $(DEFINES) $(INCPATH) pages/selecttimepage.h -o moc_selecttimepage.cpp

moc_selectcarpage.cpp: pages/page.h \
		vehiculefilterproxy.h \
		reservation.h \
		reservationmodel.h \
		station.h \
		geoposition.h \
		vehicule.h \
		pages/selectcarpage.h
	/usr/bin/moc $(DEFINES) $(INCPATH) pages/selectcarpage.h -o moc_selectcarpage.cpp

moc_confirmpage.cpp: pages/page.h \
		reservation.h \
		usagermodel.h \
		usager.h \
		geoposition.h \
		vehiculemodel.h \
		vehicule.h \
		reservationmodel.h \
		station.h \
		stationmodel.h \
		pages/confirmpage.h
	/usr/bin/moc $(DEFINES) $(INCPATH) pages/confirmpage.h -o moc_confirmpage.cpp

moc_stationsortproxy.cpp: stationsortproxy.h
	/usr/bin/moc $(DEFINES) $(INCPATH) stationsortproxy.h -o moc_stationsortproxy.cpp

moc_commentspage.cpp: pages/page.h \
		pages/commentspage.h
	/usr/bin/moc $(DEFINES) $(INCPATH) pages/commentspage.h -o moc_commentspage.cpp

moc_unexpectedpage.cpp: pages/page.h \
		pages/unexpectedpage.h
	/usr/bin/moc $(DEFINES) $(INCPATH) pages/unexpectedpage.h -o moc_unexpectedpage.cpp

moc_bookingspage.cpp: pages/page.h \
		reservationfilterproxy.h \
		reservationmodel.h \
		reservation.h \
		station.h \
		geoposition.h \
		vehicule.h \
		usager.h \
		pages/bookingspage.h
	/usr/bin/moc $(DEFINES) $(INCPATH) pages/bookingspage.h -o moc_bookingspage.cpp

moc_mymessagespage.cpp: pages/page.h \
		pages/mymessagespage.h
	/usr/bin/moc $(DEFINES) $(INCPATH) pages/mymessagespage.h -o moc_mymessagespage.cpp

moc_writecommentpage.cpp: pages/page.h \
		pages/writecommentpage.h
	/usr/bin/moc $(DEFINES) $(INCPATH) pages/writecommentpage.h -o moc_writecommentpage.cpp

moc_infostationpage.cpp: pages/page.h \
		station.h \
		geoposition.h \
		pages/infostationpage.h
	/usr/bin/moc $(DEFINES) $(INCPATH) pages/infostationpage.h -o moc_infostationpage.cpp

moc_vehiculefilterproxy.cpp: reservation.h \
		reservationmodel.h \
		station.h \
		geoposition.h \
		vehicule.h \
		vehiculefilterproxy.h
	/usr/bin/moc $(DEFINES) $(INCPATH) vehiculefilterproxy.h -o moc_vehiculefilterproxy.cpp

moc_infocarpage.cpp: vehicule.h \
		pages/page.h \
		pages/infocarpage.h
	/usr/bin/moc $(DEFINES) $(INCPATH) pages/infocarpage.h -o moc_infocarpage.cpp

moc_reservationfilterproxy.cpp: reservationmodel.h \
		reservation.h \
		station.h \
		geoposition.h \
		vehicule.h \
		usager.h \
		reservationfilterproxy.h
	/usr/bin/moc $(DEFINES) $(INCPATH) reservationfilterproxy.h -o moc_reservationfilterproxy.cpp

compiler_rcc_make_all: qrc_icones.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_icones.cpp
qrc_icones.cpp: icones.qrc \
		data/images/icons/zoom_out.png \
		data/images/icons/home.png \
		data/images/icons/zoom_in.png \
		data/icons/car_add.png \
		data/icons/email.png \
		data/icons/arrow_right.png \
		data/icons/table_multiple.png \
		data/icons/arrow_left.png \
		data/icons/tick.png \
		data/icons/pencil.png \
		data/icons/error.png \
		data/icons/help.png
	/usr/bin/rcc -name icones icones.qrc -o qrc_icones.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_cartewidget.h ui_userinterface.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_cartewidget.h ui_userinterface.h
ui_mainwindow.h: mainwindow.ui
	/usr/bin/uic mainwindow.ui -o ui_mainwindow.h

ui_cartewidget.h: cartewidget.ui
	/usr/bin/uic cartewidget.ui -o ui_cartewidget.h

ui_userinterface.h: userinterface.ui
	/usr/bin/uic userinterface.ui -o ui_userinterface.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

geoposition.o: geoposition.cpp geoposition.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o geoposition.o geoposition.cpp

geopositiondelegate.o: geopositiondelegate.cpp geoposition.h \
		geopositiondelegate.h \
		cartewidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o geopositiondelegate.o geopositiondelegate.cpp

main.o: main.cpp mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		ui_mainwindow.h \
		stationmodel.h \
		station.h \
		geoposition.h \
		vehiculemodel.h \
		vehicule.h \
		reservationmodel.h \
		reservation.h \
		usagermodel.h \
		usager.h \
		notemodel.h \
		note.h \
		reservationproxymodel.h \
		manote.h \
		geopositiondelegate.h \
		simulateur.h \
		robot.h \
		cartewidget.h \
		cartescene.h \
		carteelements.h \
		userinterface.h \
		pages/page.h \
		stationsortproxy.h \
		vehiculefilterproxy.h \
		reservationfilterproxy.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

manote.o: manote.cpp manote.h \
		note.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o manote.o manote.cpp

note.o: note.cpp note.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o note.o note.cpp

notemodel.o: notemodel.cpp notemodel.h \
		note.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o notemodel.o notemodel.cpp

reservation.o: reservation.cpp reservation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o reservation.o reservation.cpp

reservationmodel.o: reservationmodel.cpp reservationmodel.h \
		reservation.h \
		station.h \
		geoposition.h \
		vehicule.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o reservationmodel.o reservationmodel.cpp

simulateur.o: simulateur.cpp simulateur.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o simulateur.o simulateur.cpp

station.o: station.cpp station.h \
		geoposition.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o station.o station.cpp

stationmodel.o: stationmodel.cpp stationmodel.h \
		station.h \
		geoposition.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o stationmodel.o stationmodel.cpp

usager.o: usager.cpp usager.h \
		geoposition.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o usager.o usager.cpp

usagermodel.o: usagermodel.cpp usagermodel.h \
		usager.h \
		geoposition.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o usagermodel.o usagermodel.cpp

vehicule.o: vehicule.cpp vehicule.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o vehicule.o vehicule.cpp

vehiculemodel.o: vehiculemodel.cpp vehiculemodel.h \
		vehicule.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o vehiculemodel.o vehiculemodel.cpp

reservationproxymodel.o: reservationproxymodel.cpp reservationproxymodel.h \
		reservationmodel.h \
		reservation.h \
		station.h \
		geoposition.h \
		vehicule.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o reservationproxymodel.o reservationproxymodel.cpp

robot.o: robot.cpp robot.h \
		reservationmodel.h \
		reservation.h \
		station.h \
		geoposition.h \
		vehicule.h \
		usagermodel.h \
		usager.h \
		stationmodel.h \
		notemodel.h \
		note.h \
		vehiculemodel.h \
		reservationproxymodel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o robot.o robot.cpp

cartescene.o: cartescene.cpp cartescene.h \
		carteelements.h \
		geoposition.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cartescene.o cartescene.cpp

carteelements.o: carteelements.cpp carteelements.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o carteelements.o carteelements.cpp

cartewidget.o: cartewidget.cpp cartescene.h \
		carteelements.h \
		geoposition.h \
		cartewidget.h \
		ui_cartewidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cartewidget.o cartewidget.cpp

userinterface.o: userinterface.cpp userinterface.h \
		pages/page.h \
		station.h \
		geoposition.h \
		stationmodel.h \
		stationsortproxy.h \
		vehiculemodel.h \
		vehicule.h \
		usagermodel.h \
		usager.h \
		vehiculefilterproxy.h \
		reservation.h \
		reservationmodel.h \
		reservationfilterproxy.h \
		ui_userinterface.h \
		pages/mainmenupage.h \
		pages/findstationpage.h \
		pages/selectpositionpage.h \
		cartewidget.h \
		pages/selectstationpage.h \
		pages/selecttimepage.h \
		pages/selectcarpage.h \
		pages/confirmpage.h \
		pages/commentspage.h \
		pages/unexpectedpage.h \
		pages/bookingspage.h \
		pages/mymessagespage.h \
		pages/writecommentpage.h \
		pages/infostationpage.h \
		pages/infocarpage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o userinterface.o userinterface.cpp

page.o: pages/page.cpp pages/page.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o page.o pages/page.cpp

mainmenupage.o: pages/mainmenupage.cpp pages/mainmenupage.h \
		pages/page.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainmenupage.o pages/mainmenupage.cpp

findstationpage.o: pages/findstationpage.cpp pages/page.h \
		pages/findstationpage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o findstationpage.o pages/findstationpage.cpp

selectpositionpage.o: pages/selectpositionpage.cpp pages/page.h \
		pages/selectpositionpage.h \
		geoposition.h \
		cartewidget.h \
		cartescene.h \
		carteelements.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o selectpositionpage.o pages/selectpositionpage.cpp

selectstationpage.o: pages/selectstationpage.cpp pages/selectstationpage.h \
		stationsortproxy.h \
		station.h \
		geoposition.h \
		pages/page.h \
		pages/infostationpage.h \
		stationmodel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o selectstationpage.o pages/selectstationpage.cpp

selecttimepage.o: pages/selecttimepage.cpp pages/page.h \
		pages/selecttimepage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o selecttimepage.o pages/selecttimepage.cpp

selectcarpage.o: pages/selectcarpage.cpp pages/page.h \
		pages/selectcarpage.h \
		vehiculefilterproxy.h \
		reservation.h \
		reservationmodel.h \
		station.h \
		geoposition.h \
		vehicule.h \
		vehiculemodel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o selectcarpage.o pages/selectcarpage.cpp

confirmpage.o: pages/confirmpage.cpp pages/page.h \
		pages/confirmpage.h \
		reservation.h \
		usagermodel.h \
		usager.h \
		geoposition.h \
		vehiculemodel.h \
		vehicule.h \
		reservationmodel.h \
		station.h \
		stationmodel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o confirmpage.o pages/confirmpage.cpp

stationsortproxy.o: stationsortproxy.cpp stationsortproxy.h \
		station.h \
		geoposition.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o stationsortproxy.o stationsortproxy.cpp

commentspage.o: pages/commentspage.cpp pages/commentspage.h \
		pages/page.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o commentspage.o pages/commentspage.cpp

unexpectedpage.o: pages/unexpectedpage.cpp pages/unexpectedpage.h \
		pages/page.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o unexpectedpage.o pages/unexpectedpage.cpp

bookingspage.o: pages/bookingspage.cpp pages/page.h \
		pages/bookingspage.h \
		reservationfilterproxy.h \
		reservationmodel.h \
		reservation.h \
		station.h \
		geoposition.h \
		vehicule.h \
		usager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bookingspage.o pages/bookingspage.cpp

mymessagespage.o: pages/mymessagespage.cpp pages/page.h \
		pages/mymessagespage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mymessagespage.o pages/mymessagespage.cpp

writecommentpage.o: pages/writecommentpage.cpp pages/page.h \
		pages/writecommentpage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o writecommentpage.o pages/writecommentpage.cpp

infostationpage.o: pages/infostationpage.cpp pages/page.h \
		station.h \
		geoposition.h \
		pages/infostationpage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o infostationpage.o pages/infostationpage.cpp

vehiculefilterproxy.o: vehiculefilterproxy.cpp vehiculefilterproxy.h \
		reservation.h \
		reservationmodel.h \
		station.h \
		geoposition.h \
		vehicule.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o vehiculefilterproxy.o vehiculefilterproxy.cpp

infocarpage.o: pages/infocarpage.cpp pages/infocarpage.h \
		vehicule.h \
		pages/page.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o infocarpage.o pages/infocarpage.cpp

reservationfilterproxy.o: reservationfilterproxy.cpp reservationfilterproxy.h \
		reservationmodel.h \
		reservation.h \
		station.h \
		geoposition.h \
		vehicule.h \
		usager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o reservationfilterproxy.o reservationfilterproxy.cpp

moc_geopositiondelegate.o: moc_geopositiondelegate.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_geopositiondelegate.o moc_geopositiondelegate.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_note.o: moc_note.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_note.o moc_note.cpp

moc_notemodel.o: moc_notemodel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_notemodel.o moc_notemodel.cpp

moc_reservation.o: moc_reservation.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_reservation.o moc_reservation.cpp

moc_reservationmodel.o: moc_reservationmodel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_reservationmodel.o moc_reservationmodel.cpp

moc_simulateur.o: moc_simulateur.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_simulateur.o moc_simulateur.cpp

moc_station.o: moc_station.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_station.o moc_station.cpp

moc_stationmodel.o: moc_stationmodel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_stationmodel.o moc_stationmodel.cpp

moc_usager.o: moc_usager.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_usager.o moc_usager.cpp

moc_usagermodel.o: moc_usagermodel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_usagermodel.o moc_usagermodel.cpp

moc_vehicule.o: moc_vehicule.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_vehicule.o moc_vehicule.cpp

moc_vehiculemodel.o: moc_vehiculemodel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_vehiculemodel.o moc_vehiculemodel.cpp

moc_robot.o: moc_robot.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_robot.o moc_robot.cpp

moc_reservationproxymodel.o: moc_reservationproxymodel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_reservationproxymodel.o moc_reservationproxymodel.cpp

moc_cartescene.o: moc_cartescene.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_cartescene.o moc_cartescene.cpp

moc_carteelements.o: moc_carteelements.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_carteelements.o moc_carteelements.cpp

moc_cartewidget.o: moc_cartewidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_cartewidget.o moc_cartewidget.cpp

moc_userinterface.o: moc_userinterface.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_userinterface.o moc_userinterface.cpp

moc_page.o: moc_page.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_page.o moc_page.cpp

moc_mainmenupage.o: moc_mainmenupage.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainmenupage.o moc_mainmenupage.cpp

moc_findstationpage.o: moc_findstationpage.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_findstationpage.o moc_findstationpage.cpp

moc_selectpositionpage.o: moc_selectpositionpage.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_selectpositionpage.o moc_selectpositionpage.cpp

moc_selectstationpage.o: moc_selectstationpage.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_selectstationpage.o moc_selectstationpage.cpp

moc_selecttimepage.o: moc_selecttimepage.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_selecttimepage.o moc_selecttimepage.cpp

moc_selectcarpage.o: moc_selectcarpage.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_selectcarpage.o moc_selectcarpage.cpp

moc_confirmpage.o: moc_confirmpage.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_confirmpage.o moc_confirmpage.cpp

moc_stationsortproxy.o: moc_stationsortproxy.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_stationsortproxy.o moc_stationsortproxy.cpp

moc_commentspage.o: moc_commentspage.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_commentspage.o moc_commentspage.cpp

moc_unexpectedpage.o: moc_unexpectedpage.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_unexpectedpage.o moc_unexpectedpage.cpp

moc_bookingspage.o: moc_bookingspage.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_bookingspage.o moc_bookingspage.cpp

moc_mymessagespage.o: moc_mymessagespage.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mymessagespage.o moc_mymessagespage.cpp

moc_writecommentpage.o: moc_writecommentpage.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_writecommentpage.o moc_writecommentpage.cpp

moc_infostationpage.o: moc_infostationpage.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_infostationpage.o moc_infostationpage.cpp

moc_vehiculefilterproxy.o: moc_vehiculefilterproxy.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_vehiculefilterproxy.o moc_vehiculefilterproxy.cpp

moc_infocarpage.o: moc_infocarpage.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_infocarpage.o moc_infocarpage.cpp

moc_reservationfilterproxy.o: moc_reservationfilterproxy.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_reservationfilterproxy.o moc_reservationfilterproxy.cpp

qrc_icones.o: qrc_icones.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_icones.o qrc_icones.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

