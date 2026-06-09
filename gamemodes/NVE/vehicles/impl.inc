#if defined _inc_impl
    #undef _inc_impl
#endif

public OnVehicleSpawn(vehicleid)
{
    printf("%d", GetVehicleModel(vehicleid));

    if (GetVehicleModel(vehicleid) == 544)
    {
        new tmp;

        tmp = CreateDynamicObject(15065, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
        AttachDynamicObjectToVehicle(tmp, vehicleid, 0.00000, -4.15000, 0.15000, 0.0, 0.0, 0.0);

        tmp = CreateDynamicObject(15066, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
        AttachDynamicObjectToVehicle(tmp, vehicleid, 0.05000, -6.25000, 2.20000, 0.0, 0.0, 0.0);

        tmp = CreateDynamicObject(15067, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
        AttachDynamicObjectToVehicle(tmp, vehicleid, 0.05000, -6.00000, 2.25000, 0.0, 0.0, 0.0);

        tmp = CreateDynamicObject(15068, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
        AttachDynamicObjectToVehicle(tmp, vehicleid, 0.05000, -5.75000, 2.30000, 0.0, 0.0, 0.0);

        tmp = CreateDynamicObject(15069, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
        AttachDynamicObjectToVehicle(tmp, vehicleid, 0.05000, -5.50000, 2.35000, 0.0, 0.0, 0.0);
    }
    #if defined vehicle_OnVehicleSpawn
	    return vehicle_OnVehicleSpawn(vehicleid);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnVehicleSpawn
	#undef OnVehicleSpawn
#else
	#define _ALS_OnVehicleSpawn
#endif

#define OnVehicleSpawn vehicle_OnVehicleSpawn
#if defined vehicle_OnVehicleSpawn
	forward vehicle_OnVehicleSpawn(vehicleid);
#endif