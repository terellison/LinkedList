#pragma once
#include <exception>
#include <string>
class NodeNotFoundException : public std::exception {
	std::string message;
public:
	NodeNotFoundException(std::string message) {
		this->message = message;
	}

};
