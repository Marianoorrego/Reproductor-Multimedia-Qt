# Reproductor-Multimedia-
# Documentación del Proyecto: Reproductor de Video y Audio

**Autor:** Mariano Alejandro Orrego Zapata  
**Fecha:** Octubre 2024

## Tabla de Contenidos

- [Introducción](#introducción)
- [Documentación](#documentación)
  - [Librerías Utilizadas](#librerías-utilizadas)
  - [Estructura del Proyecto](#estructura-del-proyecto)
- [Manual Técnico](#manual-técnico)
  - [Configuración del Proyecto](#configuración-del-proyecto)
    - [Configuración de Librerías](#configuración-de-librerías)
    - [Compilación del Proyecto](#compilación-del-proyecto)
  - [Clase MainWindow](#clase-mainwindow)
    - [Constructor](#constructor)
    - [Conexión de Señales y Slots](#conexión-de-señales-y-slots)
    - [Función para Abrir Archivos](#función-para-abrir-archivos)
  - [Controles de Reproducción](#controles-de-reproducción)
  - [Lista de Archivos en Panel Lateral](#lista-de-archivos-en-panel-lateral)
- [Manual de Usuario](#manual-de-usuario)
  - [Introducción](#introducción)
  - [Interfaz de Usuario](#interfaz-de-usuario)
  - [Reproducción de Archivos](#reproducción-de-archivos)
  - [Selección de Archivos en el Panel Lateral](#selección-de-archivos-en-el-panel-lateral)
  - [Configuración de Volumen](#configuración-de-volumen)
  - [Finalización de la Reproducción](#finalización-de-la-reproducción)
  - [Observaciones](#observaciones)
  - [Agradecimientos](#agradecimientos)

## Introducción

Este documento proporciona una guía completa sobre el proyecto de reproductor de video y audio desarrollado en el entorno de Qt. El software permite la reproducción de archivos de video en formato **.mp4** y audio en formato **.mp3**, utilizando las bibliotecas `Qt Multimedia` y `Qt MultimediaWidgets`. El objetivo es proporcionar una herramienta fácil de usar para la visualización y escucha de medios digitales.

## Documentación

### Librerías Utilizadas

Las siguientes bibliotecas de Qt son esenciales para el funcionamiento del proyecto:

- **QtCore**: Proporciona las clases fundamentales para la programación en Qt.
- **QtGui**: Incluye elementos gráficos y de diseño de la interfaz de usuario.
- **QtWidgets**: Ofrece widgets para crear interfaces gráficas interactivas.
- **QtMultimedia**: Gestiona la reproducción de archivos multimedia (audio y video).
- **QtMultimediaWidgets**: Permite mostrar videos en la aplicación asociando un video a un widget de visualización.

### Estructura del Proyecto

El proyecto se compone de los siguientes archivos:

- `main.cpp`: Archivo de entrada de la aplicación.
- `mainwindow.cpp`: Implementación de la clase `MainWindow`, que maneja la lógica del reproductor.
- `mainwindow.h`: Definición de la clase `MainWindow`.
- `ui_mainwindow.h`: Archivo generado automáticamente que define la interfaz de usuario.
- `mainwindow.ui`: Archivo XML que describe la interfaz de usuario en formato de diseño.

## Manual Técnico

### Configuración del Proyecto

El archivo de proyecto `video.pro` contiene configuraciones esenciales para compilar la aplicación.

#### Configuración de Librerías

El archivo `video.pro` incluye las siguientes líneas para habilitar las bibliotecas necesarias:

```sh
QT       += core gui multimedia multimediawidgets
