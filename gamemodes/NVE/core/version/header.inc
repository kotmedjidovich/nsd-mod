#if defined _inc_header
    #undef _inc_header
#endif

#if !defined NVE_VERSION_TEXT
    #define NVE_VERSION_TEXT "ARP"
#endif
#if !defined NVE_VERSION_MAJOR
    #define NVE_VERSION_MAJOR v
#endif
#if !defined NVE_VERSION_MINOR
    #define NVE_VERSION_MINOR 0.0
#endif
#if !defined NVE_VERSION_BUILD
    #define NVE_VERSION_BUILD 2 beta
#endif
#define NVE_VERSION_GAMEMODE_TEXT NVE_VERSION_TEXT " " #NVE_VERSION_MAJOR "." #NVE_VERSION_MINOR  "." #NVE_VERSION_BUILD