#if defined _inc_header
    #undef _inc_header
#endif

#define COLOR_PURPLE                0xe1527eFF

CMD:me(playerid, params[])
{
    static
        str[96];
    
    if (sscanf(params, "s[96]", str)) return true;

    if (strlen(str) > 64)
    {
        SendNearbyMessagef(playerid, 30.0, COLOR_PURPLE, "* %s %.64s...", ReturnName(playerid, false), str);
        SendNearbyMessagef(playerid, 30.0, COLOR_PURPLE, "...%s", str[64]);
    }
    else
    {
        SendNearbyMessagef(playerid, 30.0, COLOR_PURPLE, "* %s %s", ReturnName(playerid, false), str);
    }
    return 1;
}

CMD:do(playerid, params[])
{
    static
        str[96];
    
    if (sscanf(params, "s[96]", str)) return true;

    if (strlen(str) > 64)
    {
        SendNearbyMessagef(playerid, 30.0, COLOR_PURPLE, "* %.64s...", str);
        SendNearbyMessagef(playerid, 30.0, COLOR_PURPLE, "...%s (( %s ))", str[64], ReturnName(playerid, false));
    }
    else
    {
        SendNearbyMessagef(playerid, 30.0, COLOR_PURPLE, "* %s (( %s ))", str, ReturnName(playerid, false));
    }
    return 1;
}

CMD:melow(playerid, params[])
{
    static
        str[96];
    
    if (sscanf(params, "s[96]", str)) return true;

    if (strlen(str) > 64)
    {
        SendNearbyMessagef(playerid, 15.0, COLOR_PURPLE, "* %s %.64s...", ReturnName(playerid, false), str);
        SendNearbyMessagef(playerid, 15.0, COLOR_PURPLE, "...%s", str[64]);
    }
    else
    {
        SendNearbyMessagef(playerid, 15.0, COLOR_PURPLE, "* %s %s", ReturnName(playerid, false), str);
    }
    return 1;
}

CMD:dolow(playerid, params[])
{
    static
        str[96];
    
    if (sscanf(params, "s[96]", str)) return true;

    if (strlen(str) > 64)
    {
        SendNearbyMessagef(playerid, 15.0, COLOR_PURPLE, "* %.64s...", str);
        SendNearbyMessagef(playerid, 15.0, COLOR_PURPLE, "...%s (( %s ))", str[64], ReturnName(playerid, false));
    }
    else
    {
        SendNearbyMessagef(playerid, 15.0, COLOR_PURPLE, "* %s (( %s ))", str, ReturnName(playerid, false));
    }
    return 1;
}

CMD:ame(playerid, params[])
{
    static
        str[96];
    
    if (sscanf(params, "s[96]", str)) return true;

    SendActionMessagef(playerid, "* %s %s", COLOR_PURPLE, 30.0, 10000, ReturnName(playerid, false), str);

    return 1;
}

CMD:ado(playerid, params[])
{
    static
        str[96];
    
    if (sscanf(params, "s[96]", str)) return true;

    SendActionMessagef(playerid, "* %s (( %s ))", COLOR_PURPLE, 30.0, 10000, str, ReturnName(playerid, false));

    return 1;
}

CMD:b(playerid, params[])
{
    static
        str[96];

    if (GetPVarInt(playerid,"mute"))
        return SendClientMessagef(playerid, -1, "У вас бан чата на %d секунд.", GetPVarInt(playerid,"mute"));

	if (sscanf(params, "s[96]", str)) return 1;

    SendNearbyMessagef(playerid, 30.0, COLOUR_WHITE, "(( %s: %s ))", ReturnName(playerid, false), str);

    return 1;
}

CMD:s(playerid, params[])
{
    static
        str[96];

    if (GetPVarInt(playerid,"mute")) 
        return SendClientMessagef(playerid, -1, "У вас бан чата на %d секунд.", GetPVarInt(playerid,"mute"));

	if (sscanf(params, "s[96]", str)) return 1;

    SendNearbyMessagef(playerid, 30.0, COLOUR_WHITE, "%s кричит: %s", ReturnName(playerid, false), str);

	return 1;
}

CMD:w(playerid, params[])
{
    static
        targetid,
        string[96]
    ;
    if (GetPVarInt(playerid,"mute"))
        return SendClientMessagef(playerid, -1, "У вас бан чата на %d секунд.", GetPVarInt(playerid,"mute"));

	if (sscanf(params, "us[96]", targetid, string)) return 1;

    SendActionMessagef(playerid, "* %s что-то шепчет %s", COLOUR_DEEP_PURPLE, 30.0, 10000, ReturnName(playerid, false), ReturnName(targetid, false));
    SendClientMessagef(targetid, COLOUR_WHITE, "%s шепчет: %s", ReturnName(playerid, false), string);
 	
	return 1;
}

CMD:todo(playerid, params[])
{
    static
        text[64],
        string[32]
    ;
    if (sscanf(params, "p<*>s[64]s[32]", text, string)) return 1;

    if (strlen(text) > 48)
    {
        SendNearbyMessagef(playerid, 30.0, COLOUR_WHITE, "%.48s...", text);
        SendNearbyMessagef(playerid, 30.0, COLOUR_WHITE, "...%s" PURPLE "- произнес %s, %s", text[48], ReturnName(playerid, false), string);
    }
    else
    {
        SendNearbyMessagef(playerid, 30.0, COLOUR_WHITE, "%s" PURPLE "- произнес %s, %s", text, ReturnName(playerid, false), string);
    }
	return 1;
}