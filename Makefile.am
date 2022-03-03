lib_LTLIBRARIES = libj2d.la

libj2d_la_SOURCES = src/drawable.c src/line.c

libj2d_la_LDFLAGS = -ljks -lgfx -version-info 1:0:0

pkgincludedir = $(includedir)/j2d
pkginclude_HEADERS = src/drawable.h src/line.h src/rect.h src/quad.h

AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = -I m4

SUBDIRS = . demo
