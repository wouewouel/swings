TEMPLATE = subdirs

SUBDIRS += \
   Qt_GL \
   general \
   text


Qt_GL.depends = general
text.depends  = general
