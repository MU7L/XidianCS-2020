LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY ALU181 IS
    PORT (
        S  : IN  STD_LOGIC_VECTOR(3 DOWNTO 0 );
        A  : IN  STD_LOGIC_VECTOR(7 DOWNTO 0);
        B  : IN  STD_LOGIC_VECTOR(7 DOWNTO 0);
        F  : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
        M  : IN  STD_LOGIC;
        CN : IN  STD_LOGIC;
        CO : OUT STD_LOGIC   );
END ALU181;
ARCHITECTURE behav OF ALU181 IS
SIGNAL A9 : STD_LOGIC_VECTOR(8 DOWNTO 0);
SIGNAL B9 : STD_LOGIC_VECTOR(8 DOWNTO 0);
SIGNAL F9 : STD_LOGIC_VECTOR(8 DOWNTO 0);
BEGIN
  A9 <= '0' & A ;  B9 <= '0' & B ;  
  PROCESS(M,CN,A9,B9)
   BEGIN
    CASE S  IS
    	WHEN "0000" =>  IF M='0' THEN F9<=A9 + CN                        ; ELSE  F9<=NOT A9;                END IF;
        WHEN "0001" =>  IF M='0' THEN F9<=(A9 or B9) + CN                ; ELSE  F9<=NOT(A9 OR B9);         END IF;
        WHEN "0010" =>  IF M='0' THEN F9<=(A9 or (NOT B9))+ CN           ; ELSE  F9<=(NOT A9) AND B9;       END IF;
        WHEN "0011" =>  IF M='0' THEN F9<= "000000000" - CN              ; ELSE  F9<="000000000";           END IF;
        WHEN "0100" =>  IF M='0' THEN F9<=A9+(A9 AND NOT B9)+ CN         ; ELSE  F9<=NOT (A9 AND B9);       END IF;
        WHEN "0101" =>  IF M='0' THEN F9<=(A9 or B9)+(A9 AND NOT B9)+CN  ; ELSE  F9<=NOT B9;                END IF;
        WHEN "0110" =>  IF M='0' THEN F9<=(A9 - B9) - CN                 ; ELSE  F9<=A9 XOR B9;             END IF;
        WHEN "0111" =>  IF M='0' THEN F9<=(A9 or (NOT B9)) - CN          ; ELSE  F9<=A9 and (NOT B9);       END IF;
        WHEN "1000" =>  IF M='0' THEN F9<=A9 + (A9 AND B9)+CN            ; ELSE  F9<=(NOT A9)and B9;        END IF;
        WHEN "1001" =>  IF M='0' THEN F9<=A9 + B9 + CN                   ; ELSE  F9<=NOT(A9 XOR B9);        END IF;
        WHEN "1010" =>  IF M='0' THEN F9<=(A9 or(NOT B9))+(A9 AND B9)+CN ; ELSE  F9<=B9;                    END IF;
        WHEN "1011" =>  IF M='0' THEN F9<=(A9 AND B9)- CN                ; ELSE  F9<=A9 AND B9;             END IF;
        WHEN "1100" =>  IF M='0' THEN F9<=(A9 + A9) + CN                 ; ELSE  F9<= "000000001";          END IF;
        WHEN "1101" =>  IF M='0' THEN F9<=(A9 or B9) + A9 + CN           ; ELSE  F9<=A9 OR (NOT B9);        END IF;
        WHEN "1110" =>  IF M='0' THEN F9<=((A9 or (NOT B9)) +A9) + CN    ; ELSE  F9<=A9 OR B9;              END IF;
        WHEN "1111" =>  IF M='0' THEN F9<=A9 - CN                        ; ELSE  F9<=A9 ;                   END IF;
        WHEN OTHERS  => F9<= "000000000" ; 
    	END CASE;
  END PROCESS;
 F<= F9(7 DOWNTO 0) ;   CO <= F9(8) ;
END behav;



