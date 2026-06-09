#if defined _inc_impl
    #undef _inc_impl
#endif

public OnGameModeInit()
{
    SetGameModeText(NVE_VERSION_GAMEMODE_TEXT);

    #if defined version_OnGameModeInit
	    return version_OnGameModeInit();
    #else
        return 1;
    #endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif

#define OnGameModeInit version_OnGameModeInit
#if defined version_OnGameModeInit
	forward version_OnGameModeInit();
#endif