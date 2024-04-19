import processing.core.PFont;
import processing.serial.*;

Serial myPort;
String inputString = "";
PrintWriter output;
String ssid = "your_SSID";
String password = "your_PASSWORD";

int SERIAL_PORT_BAUD_RATE = 115200;
int sensorValue = 0;
int pH = 0;
int temperature = 0;
int humidity = 0;
int pressure = 0;
int altitude = 0;
// Recomendaciones:
// Análisis de datos
  if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 50 && humidity <= 70 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de frutas
    Serial.println("Recomendar siembra de frutas");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de verduras
    Serial.println("Recomendar siembra de verduras");
  } else if (pH >= 5.5 && pH <= 6.5 && temperature >= 15 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 950 && pressure <= 1020) {
    // Recomendar siembra de flores
    Serial.println("Recomendar siembra de flores");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 18 && temperature <= 25 && humidity >= 70 && humidity <= 90 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de hortalizas
    Serial.println("Recomendar siembra de hortalizas");
  } else if (pH >= 5.0 && pH <= 6.0 && temperature >= 25 && temperature <= 35 && humidity >= 60 && humidity <= 80 && pressure >= 950 && pressure <= 1020) {
    // Recomendar siembra de cítricos
    Serial.println("Recomendar siembra de cítricos");
  } else if (pH >= 5.5 && pH <= 6.5 && temperature >= 18 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de hortalizas de hoja
    Serial.println("Recomendar siembra de hortalizas de hoja");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de legumbres
    Serial.println("Recomendar siembra de legumbres");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 22 && temperature <= 28 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de hortalizas de raíz
    Serial.println("Recomendar siembra de hortalizas de raíz");
  } else if (pH >= 5.5 && pH <= 6.5 && temperature >= 20 && temperature <= 30 && humidity >= 50 && humidity <= 70 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de hierbas aromáticas
    Serial.println("Recomendar siembra de hierbas aromáticas");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de tubérculos
    Serial.println("Recomendar siembra de tubérculos");
  } else if (pH >= 5.5 && pH <= 6.5 && temperature >= 18 && temperature <= 25 && humidity >= 70 && humidity <= 90 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de árboles frutales
    Serial.println("Recomendar siembra de árboles frutales");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de frutos secos
    Serial.println("Recomendar siembra de frutos secos");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 20 && temperature <= 30 && humidity >= 50 && humidity <= 70 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de especias
    Serial.println("Recomendar siembra de especias");
  } else if (pH >= 5.5 && pH <= 6.5 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas medicinales
    Serial.println("Recomendar siembra de plantas medicinales");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 70 && humidity <= 90 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas tropicales
    Serial.println("Recomendar siembra de plantas tropicales");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de bayas
    Serial.println("Recomendar siembra de bayas");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de frutos exóticos
    Serial.println("Recomendar siembra de frutos exóticos");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 22 && temperature <= 28 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de hortalizas de bulbo
    Serial.println("Recomendar siembra de hortalizas de bulbo");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de hortalizas de tallo
    Serial.println("Recomendar siembra de hortalizas de tallo");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 20 && temperature <= 30 && humidity >= 50 && humidity <= 70 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de granos
    Serial.println("Recomendar siembra de granos");
  } else if (pH >= 5.5 && pH <= 6.5 && temperature >= 18 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas ornamentales
    Serial.println("Recomendar siembra de plantas ornamentales");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 70 && humidity <= 90 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de árboles ornamentales
    Serial.println("Recomendar siembra de árboles ornamentales");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas de sombra
    Serial.println("Recomendar siembra de plantas de sombra");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas de sol
    Serial.println("Recomendar siembra de plantas de sol");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 20 && temperature <= 30 && humidity >= 50 && humidity <= 70 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas acuáticas
    Serial.println("Recomendar siembra de plantas acuáticas");
  } else if (pH >= 5.5 && pH <= 6.5 && temperature >= 18 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de enredaderas
    Serial.println("Recomendar siembra de enredaderas");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 70 && humidity <= 90 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas de interior
    Serial.println("Recomendar siembra de plantas de interior");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de arbustos
    Serial.println("Recomendar siembra de arbustos");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de árboles frutales enanos
    Serial.println("Recomendar siembra de árboles frutales enanos");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 22 && temperature <= 28 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas de estación
    Serial.println("Recomendar siembra de plantas de estación");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas de clima cálido
    Serial.println("Recomendar siembra de plantas de clima cálido");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 20 && temperature <= 30 && humidity >= 50 && humidity <= 70 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas de clima frío
    Serial.println("Recomendar siembra de plantas de clima frío");
  } else if (pH >= 5.5 && pH <= 6.5 && temperature >= 18 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas de climas templados
    Serial.println("Recomendar siembra de plantas de climas templados");
  } else {
    // No recomendar siembra de cultivos
    Serial.println("No recomendar siembra de cultivos");
    // Fin Análisis de datos
    
String recommendation = "";
String[] cropRecommendations = {
  "Recomendar siembra de frutas",
  "Recomendar siembra de verduras",
  "Recomendar siembra de flores",
  "Recomendar siembra de hortalizas",
  "Recomendar siembra de cítricos",
  "Recomendar siembra de hortalizas de hoja",
  "Recomendar siembra de legumbres",
  "Recomendar siembra de hortalizas de raíz",
  "Recomendar siembra de hierbas aromáticas",
  "Recomendar siembra de tubérculos",
  "Recomendar siembra de árboles frutales",
  "Recomendar siembra de frutos secos",
  "Recomendar siembra de especias",
  "Recomendar siembra de plantas medicinales",
  "Recomendar siembra de plantas tropicales",
  "Recomendar siembra de bayas",
  "Recomendar siembra de frutos exóticos",
  "Recomendar siembra de hortalizas de bulbo",
  "Recomendar siembra de hortalizas de tallo",
  "Recomendar siembra de granos",
  "Recomendar siembra de plantas ornamentales",
  "Recomendar siembra de árboles ornamentales",
  "Recomendar siembra de plantas de sombra",
  "Recomendar siembra de plantas de sol",
  "Recomendar siembra de plantas acuáticas",
  "Recomendar siembra de enredaderas",
  "Recomendar siembra de plantas de interior",
  "Recomendar siembra de arbustos",
  "Recomendar sios secosembra de árboles frutales enanos",
  "Recomendarcomendar siembra de plantas de estación",
  "Recomendar siembra de plantas de clima cálido",
  "Recomendar siembra de plantas de clima frío",
  "Recomendar siembra de si plantas de climas templados",
  "No recomendar siembra de cultivos"
};

int cropIndex = 0;

PFont font;
Serial arduino; 

int x = 50;
int y = 100;
int w = 750;
int h = 500;
int padding = 5;
int boxWidth = 150;
int boxHeight = 50;

int offsetX = 5;
int offsetY = 5;

int numCols = 4;
int numRows = (int)ceil((float)cropRecommendations.length / numCols);

int colWidth = (w - (padding * (numCols + 1))) / numCols;
int rowHeight =(h - (padding * (numRows + 1))) / numRows;

Boolean updateInterface = false;

void setup() {
  size(800, 600);
  myPort = new Serial(this, Serial.list()[0], SERIAL_PORT_BAUD_RATE);
  output = createWriter("data.txt");
  font = createFont("Arial", 16);
  textFont(font);

  for (int i = 0; i < numCols; i++) {
    for (int j = 0; j < numRows; j++) {
      int index = i + j * numCols;
      if (index < cropRecommendations.length) {
        int x1 = x + (i * (colWidth + padding)) + offsetX;
        int y1 = y + (j * (rowHeight + padding)) + offsetY;
        int x2 = x1 + colWidth;
        int y2 = y1 + rowHeight;

        rectMode(CORNER);
        rect(x1, y1, colWidth, rowHeight);
        textAlign(CENTER, CENTER);
        text(cropRecommendations[index], (x1 + x2) / 2, (y1 + y2) / 2 + 5);

        if (i == 0 && j == 0) {
          selectCropBox(x1, y1, colWidth, rowHeight, index);
        }
      }
    }
  }

  fill(0);
  rect(w - 50, h - 100, 50, 50);
  text("Save", w - 30, h - 50);
}

void serialEvent(Serial serial) {
  String input = serial.readString();
  if (input != null) {
    int index = input.indexOf(":");
    if (index > 0) {
      String command = input.substring(0, index);
      if (command.equals("pH")) {
        pH = int(input.substring(index + 1));
      } else if (command.equals("temp")) {
        temperature = int(input.substring(index + 1));
      } else if (command.equals("hum")) {
        humidity = int(input.substring(index + 1));
      } else if (command.equals("press")) {
        pressure = int(input.substring(index + 1));
      } else if (command.equals("alt")) {
        altitude = int(input.substring(index + 1));
      }

      updateInterface = true;
    }
  }
}

void draw() {
  if (updateInterface) {
    background(255);
    fill(0);
    text("pH: " + pH, x + padding, y + 2 * h / 5);
    text("Temperature: " + temperature, x + padding, y + 3 * h / 5);
    text("Humidity: " + humidity, x + padding, y + 4 * h / 5);
    text("Pressure: " + pressure, x + padding, y + 5 * h / 5);
    text("Altitude: " + altitude, x + padding, y + 6 * h / 5);
    updateInterface = false;

    int pHIndex = getPHIndex();
    selectCropBox(x + padding, y + h / 5, w - 2 * padding, h / 5, pHIndex);
  }
}

int getPHIndex() {
  if (pH >= 6.0 && pH <= 7.0) {
    return 0;
  } else if (pH >= 6.5 && pH <= 7.5) {
    return 1;
  } else if (pH >= 5.5 && pH <= 6.5) {
    return 2;
  } else {
    return -1;
  }
}

void selectCropBox(int x1, int y1, int width, int height, int index) {
  fill(255, 0, 0);
  rect(x1, y1, width, height);

  if (index >= 0) {
    fill(0, 255, 0);
    text(cropRecommendations[index], (x1 + x1 + width) / 2, (y1 + y1 + height) / 2);
  }
}

void mousePressed() {
  if (mouseX > w - 50 && mouseX < w && mouseY > h - 100 && mouseY < h) {
    output.flush();
    output.close();
  }

  for (int i = 0; i < numCols; i++) {
    for (int j = 0; j < numRows; j++) {
      int index = i + j * numCols;
      if (index < cropRecommendations.length) {
        int x1 = x + (i * (colWidth + padding)) + offsetX;
        int y1 = y + (j * (rowHeight + padding)) + offsetY;
        int x2 = x1 + colWidth;
    rect(x1 + 1, y1 + 1, width - 2, height - 2);

    fill(0);
        int y2 = y1 + rowHeight;

        if (mouseX > x1 && mouseX < x2 && mouseY > y1 && mouseY < y2) {
          selectCropBox(x1, y1, colWidth, rowHeight, index);
          cropIndex = index;
          break;
        }
      }
    }
  }
}
