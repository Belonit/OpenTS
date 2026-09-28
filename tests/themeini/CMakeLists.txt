# The theme reader, the sound value parsers it shares and the INI reader are compiled
# straight into the harness. It lives outside code/ so that the recursive glob building
# OpenTS cannot pick this target's entry point up.

opents_add_test(ThemeIni
    NAME themeini
    SOURCES themeini.cpp
    ENGINE
        themeini.cpp
        vocini.cpp
        ini.cpp
        utf8.cpp
        dbgprint.cpp
        b64pipe.cpp
        b64straw.cpp
        base64.cpp
        buff.cpp
        crc.cpp
        cstraw.cpp
        int.cpp
        mpmath.cpp
        pipe.cpp
        pk.cpp
        straw.cpp
        trim.cpp
        xpipe.cpp
        xstraw.cpp
    INCLUDES ${OPENTS_GENERATED_DIR}
    DEFINITIONS WIN32 _WINDOWS _MBCS NOMINMAX
    UTF8
    STAMP
)
