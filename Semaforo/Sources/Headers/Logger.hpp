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

const std::string Logger::VALUE{ ": " };

std::chrono::high_resolution_clock::time_point Logger::start{
		std::chrono::high_resolution_clock::now()
};

void Logger::info(const std::string& message)
{
	std::cout << "[" << duration() << " ms]" << "[INFO]: "
			  << message << std::endl;
}

void Logger::info(const std::string& message, uint8_t val) {
	info(message + VALUE +  std::to_string(val));
}

void Logger::info(const std::string& message0, const std::string& message1, uint8_t val0, uint8_t val1) {
	info(message0 + VALUE + std::to_string(val0) + " " + message1 + VALUE + std::to_string(val1));
}

void Logger::info(const std::string& message, uint8_t arr[], size_t n) {
	info(message + VALUE + print_array(arr, n));
}

void Logger::error(const std::string& message)
{
	std::cerr << "[" << duration() << " ms]" << "[ERROR]: "
			  << message << std::endl;
}

void Logger::error(const std::string& message, const std::exception& e)
{
	error(message);
	print_exception(e);
}

uint64_t Logger::duration()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>
			(std::chrono::high_resolution_clock::now() - start).count();
}

void Logger::print_exception(const std::exception& e, int level)
{
	std::cerr << "Caused by: " << e.what() << std::endl;
	try
	{
		std::rethrow_if_nested(e);
	}
	catch (const std::exception& ne)
	{
		print_exception(ne, level + 1);
	}
}

std::string Logger::print_array(uint8_t arr[], size_t n) {
	std::string out{ "[ " };
	for (size_t i{ 0 }; i < n; ++i) {
		out += std::to_string(arr[i]) + " ";
	}
	return out += "]";
}

std::string Logger::deduce_exception_what(const std::exception& e)
{
	try
	{
		std::rethrow_if_nested(e);
	}
	catch (const std::exception& ne)
	{
		return deduce_exception_what(ne);
	}
	return e.what();
}

void Logger::setStart()
{
	start = std::chrono::high_resolution_clock::now();
}
