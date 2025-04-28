/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:45:25 by yyamasak          #+#    #+#             */
/*   Updated: 2025/01/02 14:27:23 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int main(int argc, char **argv) {
  std::string msg;

  msg = "* LOUD AND UNBEARABLE FEEDBACL NOISE *";
  if (argc == 1)
    return (std::cout << msg << std::endl, 0);
  for (int i = 1; i < argc; i++) {
    msg = "";
    for (int j = 0; argv[i][j] != '\0'; j++)
      msg += (char)toupper(argv[i][j]);
    std::cout << msg;
    if (argv[i] != NULL)
      std::cout << " ";
  }
  std::cout << std::endl;
  return (0);
}
