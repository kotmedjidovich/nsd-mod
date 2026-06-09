#if defined _inc_NVE
    #undef _inc_NVE
#endif

#if !defined _NVE_HEADERS_INCLUDED
    #include "core\header"
    #include "players\header"
    #include "vehicles\header"
    #define _NVE_HEADERS_INCLUDED
#elseif !defined _NVE_IMPLS_INCLUDED
    #include "core\impl"
    #include "players\impl"
    #include "vehicles\impl"
    #define _NVE_IMPLS_INCLUDED
#endif