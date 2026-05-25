/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchesnea <mchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:12:33 by mchesnea          #+#    #+#             */
/*   Updated: 2026/05/25 15:02:12 by mchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class PhoneBook {

  private:
    Contact tab[8];
    int i;

  public:
    PhoneBook();
    void    Add();
    void    Search();
};