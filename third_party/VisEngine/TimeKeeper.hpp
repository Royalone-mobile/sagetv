#ifndef TimeKeeper_HPP
#define TimeKeeper_HPP

#ifndef WIN32
#include <sys/time.h>
#endif

#include "timer.h"

#define HARD_CUT_DELAY 3

class TimeKeeper
{

public:

  TimeKeeper(mathtype presetDuration, mathtype smoothDuration, mathtype easterEgg);

  void UpdateTimers();

  void StartPreset();
  void StartSmoothing();
  void EndSmoothing();
 
  bool CanHardCut();

  mathtype SmoothRatio();
  bool IsSmoothing();

  mathtype GetRunningTime(); 

  mathtype PresetProgressA();
  mathtype PresetProgressB();

  int PresetFrameA();
  int PresetFrameB();

  mathtype sampledPresetDuration();

#ifndef WIN32
  /* The first ticks value of the application */
  struct timeval startTime;
#else  
  long startTime;
#endif /** !WIN32 */

private:

  mathtype _easterEgg;
  mathtype _presetDuration;
  mathtype _presetDurationA;
  mathtype _presetDurationB;
  mathtype _smoothDuration;

  mathtype _currentTime;
  mathtype _presetTimeA;
  mathtype _presetTimeB;
  int _presetFrameA;
  int _presetFrameB;

  bool _isSmoothing;
  

};
#endif
