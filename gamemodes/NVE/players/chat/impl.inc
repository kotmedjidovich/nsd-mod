#if defined _inc_impl
    #undef _inc_impl
#endif

stock ReturnName(playerid, bool:underscore = true)
{
    static
        name[MAX_PLAYER_NAME];

    GetPlayerName(playerid, name, sizeof(name));

    if (!underscore)
    {
        for (new i; i < strlen(name); i++)
        {
            if (name[i] == '_') {
                name[i] = ' ';
            }
        }
    }
	if (GetPVarInt(playerid,"mask"))
	{
		format(name, sizeof(name), "Маска #%d", GetPVarInt(playerid,"mask"));
	}
    return name;
}

stock IsPlayerNearPlayer(playerid, targetid, Float:radius)
{
	static
		Float:x,
		Float:y,
		Float:z
    ;
	GetPlayerPos(targetid, x, y, z);

	return (GetPlayerInterior(playerid) == GetPlayerInterior(targetid) && GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(targetid)) && IsPlayerInRangeOfPoint(playerid, radius, x, y, z);
}

stock SendNearbyMessage(playerid, Float:radius, color, const text[])
{
    for (new i; i < MAX_PLAYERS; i++)
    {
        if (IsPlayerNearPlayer(i, playerid, radius)) 
        {
			SendClientMessage(i, color, text);
		}
    }
    return 1;
}

stock SendActionMessage(playerid, text[], color, Float:drawdistance, expiretime)
{
	SendClientMessage(playerid, color, text);

	SetPlayerChatBubble(playerid, text, color, drawdistance, expiretime);

	return 1;
}

stock SendNearbyMessagef(playerid, Float:radius, color, const text[], {Float,_}:...)
{
    static
	    args,
	    str[144]
    ;
	if ((args = numargs()) == 4)
	{
	    SendNearbyMessage(playerid, radius, color, text);
	}
	else
	{
		while (--args >= 4)
		{
			#emit LCTRL 5
			#emit LOAD.alt args
			#emit SHL.C.alt 2
			#emit ADD.C 12
			#emit ADD
			#emit LOAD.I
			#emit PUSH.pri
		}
		#emit PUSH.S text
		#emit PUSH.C 144
		#emit PUSH.C str
		#emit PUSH.S 8
		#emit SYSREQ.C format
		#emit LCTRL 5
		#emit SCTRL 4

		SendNearbyMessage(playerid, radius, color, str);

		#emit RETN
	}
    return 1;
}

stock SendActionMessagef(playerid, text[], color, Float:drawdistance, expiretime, {Float,_}:...)
{
	static
	    args,
	    str[144]
    ;
	if ((args = numargs()) == 5)
	{
	    SendActionMessage(playerid, text, color, drawdistance, expiretime);
	}
	else
	{
		while (--args >= 5)
		{
			#emit LCTRL 5
			#emit LOAD.alt args
			#emit SHL.C.alt 2
			#emit ADD.C 12
			#emit ADD
			#emit LOAD.I
			#emit PUSH.pri
		}
		#emit PUSH.S text
		#emit PUSH.C 144
		#emit PUSH.C str
		#emit PUSH.S 8
		#emit SYSREQ.C format
		#emit LCTRL 5
		#emit SCTRL 4

		SendActionMessage(playerid, str, color, drawdistance, expiretime);

		#emit RETN
	}
    return 1;
}

stock SendClientMessagef(playerid, color, const text[], {Float,_}:...)
{
    static
	    args,
	    str[144]
    ;
	if ((args = numargs()) == 3)
	{
	    SendClientMessage(playerid, color, text);
	}
	else
	{
		while (--args >= 3)
		{
			#emit LCTRL 5
			#emit LOAD.alt args
			#emit SHL.C.alt 2
			#emit ADD.C 12
			#emit ADD
			#emit LOAD.I
			#emit PUSH.pri
		}
		#emit PUSH.S text
		#emit PUSH.C 144
		#emit PUSH.C str
		#emit PUSH.S 8
		#emit SYSREQ.C format
		#emit LCTRL 5
		#emit SCTRL 4

		SendClientMessage(playerid, color, str);

		#emit RETN
	}
    return 1;
}