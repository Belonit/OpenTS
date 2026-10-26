# The statistics packet builder is compiled directly into this asset-free harness, which checks
# its bytes against the layout the CnCNet ladder parses.

opents_add_test(StatsContract
    NAME statspacket
    SOURCES statscontract.cpp
    ENGINE
        field.cpp
        packet.cpp
    DEFINITIONS WIN32 _WINDOWS _MBCS NOMINMAX
    LIBRARIES ws2_32
    DOCTEST
)
