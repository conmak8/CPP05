/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:23:37 by cmakario          #+#    #+#             */
/*   Updated: 2025/04/07 15:32:39 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
#define COLORS_HPP

// Reset All
#define RESET			"\033[0m"

// Text Styles
#define BOLD			"\033[1m"
#define BOLD2			"\033[1;97m"  // Bright White alternative
#define UNDERLINE		"\033[4m"

// Foreground Colors
#define BLACK			"\033[30m"
#define RED				"\033[31m"
#define GREEN			"\033[32m"
#define YELLOW			"\033[33m"
#define BLUE			"\033[34m"
#define MAGENTA			"\033[35m"
#define CYAN			"\033[36m"
#define WHITE			"\033[37m"
// #define DARK_GREY(text) "\033[1;30m" << text << "\033[0m" // Dark Grey color
#define DARK_GREY		"\033[1;30m"

// Background Colors
#define BG_BLACK		"\033[40m"
#define BG_RED			"\033[41m"
#define BG_GREEN		"\033[42m"
#define BG_YELLOW		"\033[43m"
#define BG_BLUE			"\033[44m"
#define BG_MAGENTA		"\033[45m"
#define BG_CYAN			"\033[46m"
#define BG_WHITE		"\033[47m"

// Shades of White&Gray (Foreground)
// Standard Bright White Shades (Foreground)
#define WHITE_NORMAL		"\033[37m"      // Normal white (light gray in some terminals)
#define WHITE_BOLD			"\033[1;37m"    // Bright white (bold)
#define WHITE_DIM			"\033[2;37m"    // Dim white (grayish)
// Extended Grayscale (Foreground, 256-color mode)
#define GRAY_1				"\033[38;5;250m" // Light gray
#define GRAY_2				"\033[38;5;245m" // Medium gray
#define GRAY_3				"\033[38;5;240m" // Dark gray
// True White Variants (Foreground, 256-color mode)
#define NEAR_WHITE			"\033[38;5;231m" // Almost pure white (like snow)
#define SILVER				"\033[38;5;7m"   // Silver/gray (legacy white)
#define GHOST_WHITE			"\033[38;5;255m" // Very pale white tone

// Mine
#define UBR				"\033[4m\033[1m\033[31m"

#endif // COLORS_HPP

