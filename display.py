import sys
import time
import random  # For simulation; replace with real OBD-II data
from PyQt5.QtWidgets import QApplication, QMainWindow, QVBoxLayout, QLabel, QHBoxLayout, QWidget
from PyQt5.QtCore import QTimer
from pyqtgraph import PlotWidget, plot
from qt_material import apply_stylesheet  # Optional: For modern styling
import pyqtgraph as pg

class Dashboard(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Car CAN Dashboard")
        self.setGeometry(100, 100, 800, 600)

        # Main Layout
        main_widget = QWidget()
        main_layout = QVBoxLayout()

        # Labels for gauges
        self.rpm_label = QLabel("RPM: 0")
        self.speed_label = QLabel("Speed: 0 km/h")
        self.fuel_label = QLabel("Fuel Level: 0%")
        self.coolant_label = QLabel("Coolant Temp: 0°C")
        self.battery_label = QLabel("Battery Level: 0%")

        # Layout for gauges
        gauges_layout = QHBoxLayout()
        gauges_layout.addWidget(self.rpm_label)
        gauges_layout.addWidget(self.speed_label)
        gauges_layout.addWidget(self.fuel_label)
        gauges_layout.addWidget(self.coolant_label)
        gauges_layout.addWidget(self.battery_label)

        # Graph for engine load
        self.graph_widget = PlotWidget()
        self.graph_widget.setTitle("Engine Load Over Time")
        self.graph_widget.setLabel("left", "Load (%)")
        self.graph_widget.setLabel("bottom", "Time (s)")
        self.graph_widget.showGrid(x=True, y=True)
        self.graph_data = []  # Store the last 30 seconds of engine load data

        # Add widgets to the main layout
        main_layout.addLayout(gauges_layout)
        main_layout.addWidget(self.graph_widget)

        main_widget.setLayout(main_layout)
        self.setCentralWidget(main_widget)

        # Timer for updating data
        self.timer = QTimer()
        self.timer.timeout.connect(self.update_data)
        self.timer.start(1000)  # Update every 1 second

    def update_data(self):
        # Simulated data (replace with actual OBD-II readings)
        rpm = random.randint(800, 4000)  # Replace with `connection.query(obd.commands.RPM)`
        speed = random.randint(0, 120)  # Replace with `connection.query(obd.commands.SPEED)`
        fuel = random.randint(0, 100)  # Replace with `connection.query(obd.commands.FUEL_LEVEL)`
        coolant = random.randint(70, 110)  # Replace with `connection.query(obd.commands.COOLANT_TEMP)`
        battery = random.randint(50, 100)  # Replace with actual OBD-II battery reading
        engine_load = random.randint(20, 100)  # Replace with `connection.query(obd.commands.ENGINE_LOAD)`

        # Update labels
        self.rpm_label.setText(f"RPM: {rpm}")
        self.speed_label.setText(f"Speed: {speed} km/h")
        self.fuel_label.setText(f"Fuel Level: {fuel}%")
        self.coolant_label.setText(f"Coolant Temp: {coolant}°C")
        self.battery_label.setText(f"Battery Level: {battery}%")

        # Update graph data
        self.graph_data.append(engine_load)
        if len(self.graph_data) > 30:  # Keep the last 30 seconds
            self.graph_data.pop(0)

        # Update graph
        self.graph_widget.plot(self.graph_data, clear=True)

# Run the application
if __name__ == "__main__":
    app = QApplication(sys.argv)

    # Optional: Apply a modern theme
    apply_stylesheet(app, theme='dark_blue.xml')

    dashboard = Dashboard()
    dashboard.show()
    sys.exit(app.exec_())
