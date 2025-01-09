import obd

# Connect to the OBD-II adapter
connection = obd.OBD()  # Auto-connect to the OBD port

if connection.is_connected():
    print("Connected to OBD-II adapter\n")
else:
    print("Failed to connect to OBD-II adapter. Please check the connection.")
    exit()

# Define the commands to query
commands = {
    "Calculated Engine Load": obd.commands.ENGINE_LOAD,
    "Engine Coolant Temperature": obd.commands.COOLANT_TEMP,
    "Fuel Pressure": obd.commands.FUEL_PRESSURE,
    "Intake Manifold Pressure": obd.commands.INTAKE_PRESSURE,
    "Engine RPM": obd.commands.RPM,
    "Vehicle Speed": obd.commands.SPEED,
    "Timing Advance": obd.commands.TIMING_ADVANCE,
    "Intake Air Temperature": obd.commands.INTAKE_TEMP,
    "Air Flow Rate (MAF)": obd.commands.MAF,
    "Throttle Position": obd.commands.THROTTLE_POS,
    "Engine Run Time": obd.commands.RUN_TIME,
    "Fuel Level Input": obd.commands.FUEL_LEVEL,
    "Number of Warm-Ups Since Codes Cleared": obd.commands.WARMUPS_SINCE_DTC_CLEAR,
    "Barometric Pressure": obd.commands.BAROMETRIC_PRESSURE,
    "Ambient Air Temperature": obd.commands.AMBIANT_AIR_TEMP,
    "Commanded Throttle Actuator": obd.commands.THROTTLE_ACTUATOR,
    "Time Run with MIL On": obd.commands.TIME_MIL_ON,
    "Time Since Trouble Codes Cleared": obd.commands.TIME_SINCE_DTC_CLEAR,
    "Hybrid Battery Pack Remaining Life": obd.commands.HYBRID_BATTERY_REMAINING,
    "Engine Fuel Rate": obd.commands.ENGINE_FUEL_RATE,
    "Vehicle Identification Number (VIN)": obd.commands.VIN,
}

# Query and display data
for description, command in commands.items():
    if connection.supports(command):
        response = connection.query(command)
        if response.value is not None:
            print(f"{description}: {response.value}")
        else:
            print(f"{description}: No data available")
    else:
        print(f"{description}: Not supported by this vehicle")

# Disconnect from OBD-II adapter
connection.close()
print("\nDisconnected from OBD-II adapter")
