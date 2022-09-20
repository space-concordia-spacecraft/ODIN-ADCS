% Task 1: Create a New Instance of STK from Inside MATLAB
app = actxserver('STK12.application');
app.UserControl = 1;
root = app.Personality2;
%% 
%Task 2: Create a New STK Scenario from Inside MATLAB
scenario = root.Children.New('eScenario','DIY_Matlab');
scenario.SetTimePeriod('14 Aug 2022 13:11:48.000','14 Aug 2022 15:11:48.000');
scenario.StartTime = '14 Aug 2022 13:11:48.000';
scenario.StopTime = '14 Aug 2022 15:11:48.000';
root.ExecuteCommand('Animate * Reset')
%% 
%Task 3: Insert and Configure Facilities and Satellite
facility1 = scenario.Children.New('eFacility','GroundStation');
facility1.Position.AssignGeodetic(45.6,-73.7,0);
facility2 = scenario.Children.New('eFacility','Namibia');
facility2.Position.AssignGeodetic(-21,13.6,0);
facility4 = scenario.Children.New('eFacility','Argentina');
facility4.Position.AssignGeodetic(-45.27,-68.92,0);
    %Add a satellite and configure its properties.
satellite = scenario.Children.New('eSatellite','SC-ODIN');
root.ExecuteCommand(['SetState */Satellite/SC-ODIN Classical TwoBody "',scenario.StartTime,'" "',scenario.StopTime,'" 60 ICRF "',scenario.StartTime,'" 6779000.0 0.0 51.6 0.0 0.0 0.0']);
%% 
%Task 4: Insert targets
target1nam_lat = -21;
targetlnam_long = 13.6;

Namibia = scenario.Children.New('eTarget','Namibia');
Namibia.Position.AssignGeodetic(target1nam_lat,targetlnam_long,0);
Namibia.UseTerrain = true;

target2arg_lat = 46.1991;
target2arg_long = -122.1864;

Argentina = scenario.Children.New('eTarget','Argentina');
Argentina.Position.AssignGeodetic(target2arg_lat,target2arg_long,0);
Argentina.UseTerrain = true; 
%% 
%Task 5: Adding a sensor and defining pointing
sensor = satellite.Children.New('eSensor', 'payload');
sensor.CommonTasks.SetPatternRectangular(4.055,5.4);
pointing1 = sensor.Pointing;
pointing1.Targets.AddObject(Namibia); 

% Change pattern and set
sensor.CommonTasks.SetPatternRectangular(4.055,5.4);
% Change pointing and set
sensor.CommonTasks.SetPointingFixedAzEl(90,60,'eAzElAboutBoresightRotate');
% Change location and set
sensor.SetLocationType('eSnFixed');
sensor.LocationData.AssignCartesian(-.0004,-.0004,.004);
%% 
%Task 6: Creating new vectors
vector = satellite.VO.Vector;
my_vector = vector.RefCrdns.Add('eVectorElem','Satellite/SC-ODIN AngVelocity'); %change the name AngVelocity to whichever pre-existing possible vectors you want from STK
my_vector.Visible = true;
my_vector.Color = 65535; %adjust this number to change the color
my_vector.LabelVisible = true;

%% 
%Task 7: inserting attitude file

satellite.Attitude.External.Load('C:\Program Files\AGI\STK 11\Help\stktraining\text\AttitudeTimeEulerAngles_Example.a');
% replace the file directory for the AttitudeDatatSCODIN file in the brackets above ^^^ to make that function work
