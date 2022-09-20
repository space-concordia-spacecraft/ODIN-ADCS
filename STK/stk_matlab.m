
% % Get reference to running STK instance
% uiApplication = actxGetRunningServer('STK12.Application');
% 
% % Get our IAgStkObjectRoot interface
% root = uiApplication.Personality2;

% IAgStkObjectRoot root: STK Object Model Root
% satellite = root.CurrentScenario.Children.New('eSatellite', 'ODIN');
% 
% % IAgSatellite satellite: Satellite object
% satellite.SetPropagatorType('ePropagatorSGP4');
% propagator = satellite.Propagator;
% propagator.EphemerisInterval.SetImplicitInterval( ...
%     root.CurrentScenario.Vgt.EventIntervals.Item("AnalysisInterval")) % Link to scenario period
% propagator.CommonTasks.AddSegsFromOnlineSource('25544'); % International Space Station
% propagator.AutoUpdateEnabled = true;
% propagator.Propagate();

start_time = datestr([2022 08 14 13 11 48],'dd mmm yyyy HH:MM:SS.FFF');

fileID = fopen('AttitudeDataSCODIN.a','w');
fprintf(fileID,'stk.v.12.5\n');
fprintf(fileID,'BEGIN Attitude\n');
fprintf(fileID,'NumberOfAttitudePoints\t %6.0f\n',length(q_BN));
fprintf(fileID,'ScenarioEpoch\t %s\n',start_time);
fprintf(fileID,'BlockingFactor\t 20\n');
fprintf(fileID,'InterpolationOrder\t 1\n');
fprintf(fileID,'CentralBody\t Earth\n');
fprintf(fileID,'CoordinateAxes\t J2000\n');
fprintf(fileID,'AttitudeTimeQuaternions\n');
fprintf(fileID,'%4.2f %1.7f %1.7f %1.7f %1.7f\n',transpose(q_BN));
fprintf(fileID, 'END Attitude\n');
fclose(fileID);

% satellite.Attitude.External.Load('C:\Users\mario\Desktop\Spacecraft\ODIN-ADCS\AttitudeDataSCODIN.a');

% IAgSatellite satellite: Satellite object
% satellite.Attitude.External.Load('C:\Users\mario\Desktop\Spacecraft\ODIN-ADCS\STK\AttitudeDataSCODIN.a');