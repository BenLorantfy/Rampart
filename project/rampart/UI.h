/* ================================================ *
 *											 		*
 * 		FILE 			: UI.h 						*
 * 		PROJECT 		: DS/OOP final project		*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-04-18 				*
 * 		DESCRIPTION		: UI class defination		*
 *													*
 * ================================================ */
 
/// 
/// \class WallOverlay
///
/// \brief This class is used to serve as the user interface for the game. This is done by acting as the interface between the Game class and the user.
///
/// \author Ben Lorantfy
///


#define PLAYER1 0
#define PLAYER2 1

#define CANNON_OFFSET 4
#define CASTLE_OFFSET 5
#define KEYS_OFFSET 20




class UI{
private:
	KeyBoard keyboard;
	Game	 game;
	
	int width;
	int height;

	int timeLeft;
public:
	///
	/// \details <b>Details</b>
	/// Shows the menu
	///
	bool ShowMenu(void);

	///
	/// \details <b>Details</b>
	/// Shows the instructions
	///
	void ShowInstructions(void);

	///
	/// \details <b>Details</b>
	/// Asks for size of screen
	///
	void AskWhatSize(void);

	///
	/// \details <b>Details</b>
	/// Creates a new game object with width/height
	///
	void StartGame(void);

	///
	/// \details <b>Details</b>
	/// Starts the select base stage
	///
	void SelectBase(void);

	///
	/// \details <b>Details</b>
	/// Starts the place cannons stage
	///
	void PlaceCannons(int duration=30);

	///
	/// \details <b>Details</b>
	/// Starts the repair walls stage
	///
	void RepairWalls(int duration=30);

	///
	/// \details <b>Details</b>
	/// Starts the fire cannons stage
	///
	void FireCannons(int duration=30);


	///
	/// \details <b>Details</b>
	/// Update's the timer
	///
	void UpdateTimer(void);
	
	///
	/// \details <b>Details</b>
	/// Increases the number of possible wall types
	///
	/// \note
	/// Use this to increase difficulty
	///
	void MoreWallTypes(void);

	///
	/// \details <b>Details</b>
	/// Checks player 1's controls for keypresses, doing the appropiate wall actions
	///
	void ControlPlayer1Wall(void);


	///
	/// \details <b>Details</b>
	/// Checks player 2's controls for keypresses, doing the appropiate wall actions
	///
	void ControlPlayer2Wall(void);

	///
	/// \details <b>Details</b>
	/// Checks player 1's controls for keypresses, doing the appropiate cannon actions
	///
	void ControlPlayer1Cannon(void);

	///
	/// \details <b>Details</b>
	/// Checks player 2's controls for keypresses, doing the appropiate cannon actions
	///
	void ControlPlayer2Cannon(void);

	///
	/// \details <b>Details</b>
	/// Checks player 1's controls for keypresses, doing the appropiate target actions
	///
	void ControlPlayer1Target(void);

	///
	/// \details <b>Details</b>
	/// Checks player 2's controls for keypresses, doing the appropiate target actions
	///
	void ControlPlayer2Target(void);

	///
	/// \details <b>Details</b>
	/// Checks player's 1 controls for keypresses, doing the appropiate base actions
	///
	bool ControlPlayer1BaseSelection(void);

	///
	/// \details <b>Details</b>
	/// Checks player's 2 controls for keypresses, doing the appropiate base actions
	///
	bool ControlPlayer2BaseSelection(void);
	
	///
	/// \details <b>Details</b>
	/// Gets a code representing the outcome
	///
	int GetOutcome(void);

	///
	/// \details <b>Details</b>
	/// Shows the victory screen
	///
	void ShowVictoryScreen(int player);

};