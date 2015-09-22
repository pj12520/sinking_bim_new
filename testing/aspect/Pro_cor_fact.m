function [ cor_fact ] = Pro_cor_fact( long, short )
%Pro_cor_fact Given the minor and major semi-axes of a prolate spheroid,
%calculate the correction factor to Stokes law in the case translation is
%parallel to the long axis. From Happel and Brenner 1973, equation 3-30.12,
%page 156

tau = (1.0 - (short / long) * (short / long))^-0.5;

cor_fact = 4.0 / (3.0 * sqrt(tau * tau - 1) * ((tau * tau + 1) * acoth(tau) - tau));


end

