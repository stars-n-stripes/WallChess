//
// Created by ace09 on 1/5/2021.
//

#ifndef WALLCHESS___CLIENT_H
#define WALLCHESS___CLIENT_H

#include <string>
#include <iostream>
namespace Chess {

    enum class CLIENTTYPE {SYNCHRONOUS, ASYNCHRONOUS};
    enum class VARIANT {STANDARD, CHESS960};

/// Abstract class for a client-to-board interface
/// All clients (console, remote, local, etc) need to implement the functions declared here.
/// This allows the GameBoard to run a game regardless of the backend which handles user input
    class Client {
    private:
        //stuff
        bool replaceme = true;
        std::string LastMove;
        CLIENTTYPE Type;
        virtual std::string MakeMoveSync() = 0;
        virtual std::string MakeMoveAsync() = 0;
        bool OutboundDrawFlag = false;
        bool InboundDrawFlag = false;
        std::ostream *OutputStream; // Where the client shouild write its results
    public:
        /// overloaded << operator allowing the board to write to the client's iostream
        /// This is done to open up the possibility of chatting/other interactions while waiting for a response.
        /// https://levelup.gitconnected.com/learning-c-overloading-the-input-and-output-operators-807564b33e62
        friend std::istream &operator>>(std::istream &is, Client &c) {
            is >> c.LastMove;
            if (c.Type == CLIENTTYPE::SYNCHRONOUS){
                // Blocking call to adjudicate move
                c.MakeMoveSync();
            }
            else {
                // Non-Blocking call to adjudicate move

            }
            return is; // Must return or "give back" the iostream that was given to us
        }

        void SetOutputStream(std::ostream &os){
            this->OutputStream = &os;
        }

        /// Set the draw flag of the client. This will tell the client to transmit a draw request the next time it sends a move
        /// @param flag_state: the flag
        void SetDrawFlag(bool flag_state){
            this->OutboundDrawFlag  = flag_state;
        }

        /// Transmit a response to a previous draw request. This is synchronous regardless of client type
        /// @param answer: Answer to the inbound draw request, with true indicating acceptance
        virtual bool ReplyToDraw(bool answer) = 0;

        /// Transmit a chat message.
        virtual bool SendChat(std::string msg) = 0;

        /// Terminate the game via resignation
        /// Returns true if the resignation is successfully transmitted; false otherwise
        virtual bool Resign() = 0;

        /// Terminate the game without notifying the other client. Should only be used to ease crash handling
        virtual void Terminate() = 0;

        /// Blocking call that searches for a game against an anonymous human player
        /// Returns true if a game is found, false if the backend gives up
        virtual bool FindGame() = 0;

        /// Blocking call that waits for a human player to connect to this program
        /// Mainly to be used for console testing
        virtual void WaitForPlayer() = 0;

        /// Call that sets up a game with an AI, if possible.
        /// @param difficulty: number in the range (0, 1] that indicates the relative difficulty of the AI to play
        virtual void StartAIGame(float difficulty) = 0;

        /// Authenticate with whatever system exists on the backend
        /// If there is no authentication schema, it is on the concrete implementation to simply return true;
        virtual bool Authenticate(std::string username, std::string password) = 0;

    };
}

#endif //WALLCHESS___CLIENT_H
