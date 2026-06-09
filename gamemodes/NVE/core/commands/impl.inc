#if defined _inc_impl
    #undef _inc_impl
#endif

public OnPlayerCommandText(playerid, cmdtext[])
{
    static
        command[32] = {'c', 'm', 'd', '_'},
        params[96]
    ;
    sscanf(cmdtext[1], "s[24]s()[96]", command[4], params);

    #if defined OnPlayerCommandReceived
        if (!OnPlayerCommandReceived(playerid, cmdtext)) return 1;
    #endif
    #if defined OnPlayerCommandPerformed
        OnPlayerCommandPerformed(playerid, cmdtext, CallLocalFunction(command, "is", playerid, (params[0]) ? (params) : ("\1")));
    #else
        CallLocalFunction(command, "is", playerid, (params[0]) ? (params) : ("\1"));
    #endif
    #if defined commands_OnPlayerCommandText
	    return commands_OnPlayerCommandText(playerid, cmdtext);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerCommandText
	#undef OnPlayerCommandText
#else
	#define _ALS_OnPlayerCommandText
#endif

#define OnPlayerCommandText commands_OnPlayerCommandText
#if defined commands_OnPlayerCommandText
	forward commands_OnPlayerCommandText(playerid, cmdtext[]);
#endif