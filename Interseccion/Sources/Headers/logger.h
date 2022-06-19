// Copyright 2022 Ariel Arevalo Alvarado <ariel.arevalo@ucr.ac.cr>.

#pragma once

#include <chrono>
#include <cstdint>
#include <iostream>
#include <string>

/**
 * @brief Logs info and error messages, and unwinds nested exceptions.
 */
class Logger
{
public:
	/**
	 * @brief Logs info messages with timestamp.
	 * @param message Message to log.
	 */
	static void info(const std::string& message);

	static void info(const std::string& message, uint8_t val);

	static void info(const std::string& message0, const std::string& message1, uint8_t val0, uint8_t val1);

	static void info(const std::string& message, uint8_t arr[], size_t n);

	/**
	 * @brief Logs error messages with timestamp.
	 * @param message Message to log.
	 */
	static void error(const std::string& message);

	/**
	 * @brief Logs error messages with timestamp and exception unwinding.
	 * @param message Message to log.
	 * @param e Exception to unwind.
	 */
	static void error(const std::string& message, const std::exception& e);

	/**
	 * @brief Unwinds a nested exception to return the descriptive message of
	 * the bottom level exception.
	 * @param e Exception to unwind and deduce.
	 * @return Descriptive message of bottom level exception.
	 */
	static std::string deduce_exception_what(const std::exception& e);

	/**
 	 * @brief Sets internal timer to zero.
	 */
	static void setStart();

private:
	/**
	 * @brief Determines the time it takes to process each method or action.
 	 * @details Method that records the processing time
	 * @return u_int64_t value
	 */
	static uint64_t duration();

	/**
	 * @brief Unwinds exception and prints each level.
	 * @param e Exception to unwind.
	 * @param level Current unwind depth level.
	 */
	static void print_exception(const std::exception& e, int level = 0);

	static const std::string VALUE;

	static std::string print_array(uint8_t arr[], size_t n);

	static std::chrono::high_resolution_clock::time_point start;
};
