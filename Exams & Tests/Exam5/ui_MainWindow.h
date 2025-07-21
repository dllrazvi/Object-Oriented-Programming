<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>MainWindow</class>
 <widget class="QMainWindow" name="MainWindow">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>800</width>
    <height>600</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>MainWindow</string>
  </property>
  <widget class="QWidget" name="centralwidget">
   <widget class="QPushButton" name="btnAddVolunteer">
    <property name="geometry">
     <rect>
      <x>370</x>
      <y>280</y>
      <width>75</width>
      <height>24</height>
     </rect>
    </property>
    <property name="text">
     <string>PushButton</string>
    </property>
   </widget>
   <widget class="QPushButton" name="btnSaveNewVolunteer">
    <property name="geometry">
     <rect>
      <x>350</x>
      <y>330</y>
      <width>75</width>
      <height>24</height>
     </rect>
    </property>
    <property name="text">
     <string>PushButton</string>
    </property>
   </widget>
   <widget class="QLineEdit" name="editName">
    <property name="geometry">
     <rect>
      <x>20</x>
      <y>260</y>
      <width>113</width>
      <height>21</height>
     </rect>
    </property>
   </widget>
   <widget class="QLineEdit" name="editEmail">
    <property name="geometry">
     <rect>
      <x>20</x>
      <y>300</y>
      <width>113</width>
      <height>21</height>
     </rect>
    </property>
   </widget>
   <widget class="QLineEdit" name="editInterests">
    <property name="geometry">
     <rect>
      <x>30</x>
      <y>340</y>
      <width>113</width>
      <height>21</height>
     </rect>
    </property>
   </widget>
   <widget class="QListWidget" name="listVolunteers">
    <property name="geometry">
     <rect>
      <x>20</x>
      <y>20</y>
      <width>256</width>
      <height>192</height>
     </rect>
    </property>
   </widget>
   <widget class="QListWidget" name="listUnassignedVolunteers">
    <property name="geometry">
     <rect>
      <x>230</x>
      <y>20</y>
      <width>256</width>
      <height>192</height>
     </rect>
    </property>
   </widget>
  </widget>
  <widget class="QMenuBar" name="menubar">
   <property name="geometry">
    <rect>
     <x>0</x>
     <y>0</y>
     <width>800</width>
     <height>22</height>
    </rect>
   </property>
   <widget class="QMenu" name="menudadw">
    <property name="title">
     <string>dadw</string>
    </property>
   </widget>
   <addaction name="menudadw"/>
  </widget>
  <widget class="QStatusBar" name="statusbar"/>
 </widget>
 <resources/>
 <connections/>
</ui>
