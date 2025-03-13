#pragma once

#include <string>
#include <any>

#include "../utils/macros.hpp"

enum class TokenType : uint8_t {
    // Single-character tokens
    LEFT_PAREN = 1, RIGHT_PAREN = 2, LEFT_BRACE = 3, RIGHT_BRACE = 4,
    COMMA = 5, DOT = 6, MINUS = 7, PLUS = 8, SEMICOLON = 9, SLASH = 10, STAR = 11,

    // One/two-character tokens
    BANG = 12, BANG_EQUAL = 13, EQUAL = 14, EQUAL_EQUAL = 15, GREATER = 16,
    GREATER_EQUAL = 17, LESS = 18, LESS_EQUAL = 19,

    // Literals
    IDENTIFIER = 20, STRING = 21, NUMBER = 22,

    // Keywords
    AND = 23, CLASS = 24, ELSE = 25, FALSE_ = 26, FUN = 27, FOR = 28, IF = 29, NIL = 30, OR = 31,
    PRINT = 32, RETURN = 33, SUPER = 34, THIS = 35, TRUE_ = 36, VAR = 37, WHILE = 38,

    END_OF_FILE,
};

struct Token {
    TokenType type_;
    std::string lexeme_;
    std::any literal_;
    int line_;

    Token(TokenType type, std::string lexeme, std::any literal, int line) : type_(type), lexeme_(lexeme), literal_(literal), line_(line) {}

    std::string stringifyType() {
        switch (type_) {
            case TokenType::LEFT_PAREN: return "LEFT_PAREN";
            case TokenType::RIGHT_PAREN: return "RIGHT_PAREN";
            case TokenType::LEFT_BRACE: return "LEFT_BRACE";
            case TokenType::RIGHT_BRACE: return "RIGHT_BRACE";
            case TokenType::COMMA: return "COMMA";
            case TokenType::DOT: return "DOT";
            case TokenType::MINUS: return "MINUS";
            case TokenType::PLUS: return "PLUS";
            case TokenType::SEMICOLON: return "SEMICOLON";
            case TokenType::SLASH: return "SLASH";
            case TokenType::STAR: return "STAR";
            case TokenType::BANG: return "BANG";
            case TokenType::BANG_EQUAL: return "BANG_EQUAL";
            case TokenType::EQUAL: return "EQUAL";
            case TokenType::EQUAL_EQUAL: return "EQUAL_EQUAL";
            case TokenType::GREATER: return "GREATER";
            case TokenType::GREATER_EQUAL: return "GREATER_EQUAL";
            case TokenType::LESS: return "LESS";
            case TokenType::LESS_EQUAL: return "LESS_EQUAL";
            case TokenType::IDENTIFIER: return "IDENTIFIER";
            case TokenType::STRING: return "STRING";
            case TokenType::NUMBER: return "NUMBER";
            case TokenType::AND: return "AND";
            case TokenType::CLASS: return "CLASS";
            case TokenType::ELSE: return "ELSE";
            case TokenType::FALSE_: return "FALSE";
            case TokenType::FUN: return "FUN";
            case TokenType::FOR: return "FOR";
            case TokenType::IF: return "IF";
            case TokenType::NIL: return "NIL";
            case TokenType::OR: return "OR";
            case TokenType::PRINT: return "PRINT";
            case TokenType::RETURN: return "RETURN";
            case TokenType::SUPER: return "SUPER";
            case TokenType::THIS: return "THIS";
            case TokenType::TRUE_: return "TRUE";
            case TokenType::VAR: return "VAR";
            case TokenType::WHILE: return "WHILE";
            case TokenType::END_OF_FILE: return "END_OF_FILE";
        }

        UNREACHABLE_CODE
        return "";
    }
};