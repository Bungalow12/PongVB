#ifndef PONG_MANAGER_H_
#define PONG_MANAGER_H_

#include <ListenerObject.h>
#include <Stage.h>

#define DISK_NAME "Disk"

class PongManager : ListenerObject
{
	/// @privatesection

	/// Scoring
	uint32 leftScore;
	uint32 rightScore;

	/// @publicsection
	
	/// Class' constructor
	void constructor(Stage stage);

	/// Process an event that the instance is listen for.
    /// @param eventFirer: ListenerObject that signals the event
    /// @param eventCode: Code of the firing event
    /// @return False if the listener has to be removed; true to keep it
	override bool OnEvent(ListenerObject eventFirer, uint16 eventCode);

	/// Class' destructor
	void destructor();
}

#endif
