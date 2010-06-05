#ifndef __OUTPUT_MESSAGE_BUFFER_H__
#define __OUTPUT_MESSAGE_BUFFER_H__

#include <string>

/**
 * Associates a single message with a type.
 *
 * This is used by the QueryOutputWindow.
 */
class QueryOutputMessage
{
	public:
		/**
		 * Types of messages which can be used.
		 */
		enum Type 
		{ 
			INPUT, 	/**< User input **/
			OUTPUT, /**< SQL server output **/
			ERROR 	/**< SQL server error **/
		};

		/**
		 * Initialize a message.
		 *
		 * @param message The message text.
		 * @param type The message type.
		 */
		QueryOutputMessage(std::string message, Type type);
		~QueryOutputMessage();

		/**
		 * Getter for the message.
		 *
		 * @return The message.
		 */
		std::string getMessage();

		/**
		 * Getter for the type.
		 *
		 * @return The message type.
		 */
		Type getType();

	private:
		Type type;
		std::string message;
};

#endif
