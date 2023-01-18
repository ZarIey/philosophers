NAME 	= 	philo
FILES	= 	philo	\
			parsing	\

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

SRCS_B_DIR = ./bonus/
SRCS_B = $(addprefix $(SRCS_B_DIR), $(addsuffix .c, $(FILES_B)))

OBJS_B_DIR = ./bonus/
OBJS_B = $(addprefix $(OBJS_B_DIR), $(addsuffix .o, $(FILES_B)))

LIBFT_DIR = ./includes/libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g -fsanitize=address -ofast
LIBRARIES = -lft -L$(LIBFT_DIR)
HEADERS = -I$(LIBFT_DIR)
.c.o		:
				${CC} ${CFLAGS} ${HEADERS} -c $< -o ${<:.c=.o}

${NAME} 	:	$(LIBFT) ${OBJS}
				@${CC} ${CFLAGS} ${LIBRARIES} ${OBJS} -o $@
				@echo "\033[32m\n🍽  Philosophers Compiled !\n"


$(LIBFT)	:	
				@echo "\033[32m\n🧠 Compiling ... \n\033[33;1m"
				@$(MAKE) -C $(LIBFT_DIR)
				@echo "\033[32m\n😎 Libft Compiled !\n\033[33;1m"

${BONUS}	:	$(LIBFT) ${OBJS_B}
				@${CC} ${CFLAGS} ${LIBRARIES} ${OBJS_B} -o $@
				@echo "\033[32m\n📊 Checker Compiled !\n"
				
all			:	${NAME}

bonus		:	${NAME} ${BONUS}


clean		:	
				@echo "\033[32m\n🧻 Clean ... \n\033[33;1m"
				@rm -rf ${OBJS} ${OBJS_B}
				@$(MAKE) clean -C $(LIBFT_DIR)
				@echo "\033[32;1m\n🗑  Deleting all '.o' files !\n"

fclean 		:	clean
				@echo "\033[32m\n🧻 Fclean ... \n\033[33;1m"
				@rm -rf ${NAME} ${BONUS}
				@$(MAKE) fclean -C $(LIBFT_DIR)
				@echo "\033[32;1m\n🗑  Deleting everything !\n"

re 			:	fclean all
				@echo "\033[32;1m\n🔄 Reset made !\n"
ayaya 		:
			@for (( i=1; i<=10000; i++ )) \
			do \
				echo " 	\033[33m⡿⠋⠄⣀⣀⣤⣴⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣌⠻⣿⣿" ; \
			echo " 	⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⠹⣿" ; \
			echo "	⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠹" ; \
			echo "	⣿⣿⡟⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡛⢿⣿⣿⣿⣮⠛⣿⣿⣿⣿⣿⣿⡆" ; \
			echo "	⡟⢻⡇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣣⠄⡀⢬⣭⣻⣷⡌⢿⣿⣿⣿⣿⣿" ; \
			echo "	⠃⣸⡀⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠈⣆⢹⣿⣿⣿⡈⢿⣿⣿⣿⣿" ; \
			echo "	⠄⢻⡇⠄⢛⣛⣻⣿⣿⣿⣿⣿⣿⣿⣿⡆⠹⣿⣆⠸⣆⠙⠛⠛⠃⠘⣿⣿⣿⣿" ; \
			echo "	⠄⠸⣡⠄⡈⣿⣿⣿⣿⣿⣿⣿⣿⠿⠟⠁⣠⣉⣤⣴⣿⣿⠿⠿⠿⡇⢸⣿⣿⣿" ; \
			echo "	⠄⡄⢿⣆⠰⡘⢿⣿⠿⢛⣉⣥⣴⣶⣿⣿⣿⣿⣻⠟⣉⣤⣶⣶⣾⣿⡄⣿⡿⢸" ; \
			echo "	⠄⢰⠸⣿⠄⢳⣠⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣼⣿⣿⣿⣿⣿⣿⡇⢻⡇⢸" ; \
			echo "	⢷⡈⢣⣡⣶⠿⠟⠛⠓⣚⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⢸⠇⠘" ; \
			echo "	⡀⣌⠄⠻⣧⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠛⠛⠛⢿⣿⣿⣿⣿⣿⡟⠘⠄⠄" ; \
			echo "	⣷⡘⣷⡀⠘⣿⣿⣿⣿⣿⣿⣿⣿⡋⢀⣠⣤⣶⣶⣾⡆⣿⣿⣿⠟⠁⠄⠄⠄⠄" ; \
			echo "	⣿⣷⡘⣿⡀⢻⣿⣿⣿⣿⣿⣿⣿⣧⠸⣿⣿⣿⣿⣿⣷⡿⠟⠉⠄⠄⠄⠄⡄⢀" ; \
			echo "	⣿⣿⣷⡈⢷⡀⠙⠛⠻⠿⠿⠿⠿⠿⠷⠾⠿⠟⣛⣋⣥⣶⣄⠄⢀⣄⠹⣦⢹⣿ " ; \
			echo $$i AYAYA\\n; \
			done

julien		:
			@for (( i=1; i<=10000; i++ )) \
			do \
				echo " Ok blc $$i fois 👍" ; \
			done

sonic		: 
			@for (( i=1; i<=10000; i++ )) \
			do \
				make sonic1 sonic2 sonic3 sonic4 sonic5 sonic6 sonic7 sonic8 ; \
			done
		

sonic1 		: 
	@clear
	@echo "\033[34m                           :..                                             "          
	@echo "                                 :^~:.                                             "          
	@echo "                              ..^~~:.                                              "          
	@echo "                            .:^~~~~.                                               "          
	@echo "                          .:^~~~~^:                                                "          
	@echo "                        .:^~~~~~^..                                                "          
	@echo "                       .:~~~~~~^.   .:::::::....                                   "          
	@echo "                      :^~~~~~~^:.:::^~~~~~^::...                                   "          
	@echo "                      ^^~~~~~^^^~~~~~~~~^.    ..              :^                   "          
	@echo "                 .:P!.^^~~~~~^~~~~~~~~:.    .:..        ...?J5GG.                  "          
	@echo "                .:~GGB7!^~~~~~~~~~~~^......:::..     :^~5G##B555..                 "          
	@echo "                 .:~5#5J~~~~~~~~~^^^^^~~~~~^^.:::. 7??B@@@@PP#BG.                  "          
	@echo "                   .^!^^^^^~~~~~~^^~~~~~~^^.:~5GG7.&B7B@@@@PY~^:                   "          
	@echo "                   ..:~?##G:^~~~~~~~~~~~:..GB#BGJ7!^^:^~G#@PY7:                    "          
	@echo "                    ..^J@@@GJ~~7GGG!~~^::?P&GJ~^:::.    ^~!GBB!                    "          
	@echo "                     .:~?5G@Y:PB&&&G?..^PJ77!::::.         :::.                    "          
	@echo "                     .::^^~@GJ&B?GB?~ J557~~~^:.                                   "          
	@echo "                        .:~GB#YJJ!^  .B&&GY~~~:..                                  "          
	@echo "                      ...^~!!!..:     ~7PP5~~~...   ...:~:                         "          
	@echo "                                        ^^^~^:..   ::^::7~.                        "          
	@echo "                                        . .^^~::...::.JPJ!......                   "          
	@echo "                                      ..:...::^^^^^^^::^@BP!^^JP.                  "          
	@echo "                                       .::::...:7!~...7Y@&#??Y#&..                 "          
	@echo "                                              ..!~^  .!7!?J55!B@..                 "          
	@echo "                                                      .. 7GBP!5G.                  "          
	@echo "                                                   ...^~~~~YP@7                    "          
	@echo "                                                 .^!77?????7Y@7                    "          
	@echo "                                                 ^7J5GGGGGGGY:.                    "          
	@echo "                                                  ..........    "
	@sleep 0.01

sonic2 		:
	@clear
	@echo "                                  . ::.                                            "         
	@echo "                              ...^^^:.                                             "         
	@echo "                            .:^~~~^.                                               "         
	@echo "                          .:^~~~~:.       ...                                      "         
	@echo "                        .:~~~~~~:.      .^^:                                       "         
	@echo "                       .:^~~~~^^....^^^^^^.              ..^~                      "         
	@echo "                       :^~~~~~^^^~~~~~~~:            .^~JBPGP.                     "         
	@echo "                    .^Y~^~~~~^~~~~~~~^:     .:..  :~JP#@BYGG5.                     "         
	@echo "                   ..!&GJ^~~~~~~~~~~:.....:::.:^ PG?&@@#G55J7.                     "         
	@echo "                   :.!#Y?~~~~~~~~^^^^^~~~~^::JBB^??~5B@G5JY~                       "         
	@echo "                    .:~^~!!~^~~~~^^~~~~~^::J##Y!.   .:^~~~~:                       "         
	@echo "                      .^Y@@BJ~~!55J~~~^::~B5?^.                                    "         
	@echo "                      .:!JG&&^?G&&#P^..^?G7^.::..                                  "         
	@echo "                       .:^^Y@JB&JGG7.~55?~~^^:.                                    "         
	@echo "                         .:?GBY??~:  !&&B5~~~.                                     "         
	@echo "                         .^^^^. .    .~JJ7^~~^..                                   "         
	@echo "                                  .::..:. ^::~^:.             ..:                  "         
	@echo "                                   .... :~P5J.:^^^:.  .!?JJ!^^~?#^                 "         
	@echo "                                      .:7PPPY^^:.:^^^^^^5@@&G77?5GJ                "         
	@echo "                                      .7??57^^^~?:. ... ?#GY?7JYJ&P                "         
	@echo "                                         .JYYY7!P^     .:^..:YBP~B5:               "         
	@echo "                                       .:^^7YGJ!.            ^YP57Y@:              "         
	@echo "                                     :~!!!JJ?~.            :^!!!!!Y@^              "         
	@echo "                                    .^???7...             !?Y5555555.              "         
	@echo "                                                          ^^~!!!!!^                "         
	@sleep 0.01                                                                                                

                                                                                                   
                                        
sonic3		: 
	@clear
	@echo "	                                  ........                                              "            
	@echo "                               :::~~~^:.....                                             "           
	@echo "                           .^^^~~~~^:   .::.                                             "           
	@echo "                         :^~~~~~~^:. ::^~:.                                              "           
	@echo "                      .:^~~~~~~^::^^^^~~^.                                               "           
	@echo "                      .:~~~~~^^^~~~~~~^:.                ..                              "           
	@echo "                     .!J:^~~^^~~~~~~~:.             . 7YJPJ                              "           
	@echo "                    .5#&.^~~~~~~~~~^.....::::::..:~?PBGPPPJ.                              "          
	@echo "                    .BP?~~~~~~~~~^^^^~~~~^^.:..JJ?@@@@BPBGJ    ...                        "          
	@echo "                    .^^^!!!^~~~~~^~~~~~^::~?GY:G57G#&@B57:    .J5P~.                      "          
	@echo "                     .:!@@&Y!~~Y55~~~^:^JGB5?!^... ^7JJJJ:   :!77?PY?.                    "          
	@echo "                     .:^?PB@7!P&&&P7..75J7~::::.         ^~^???777!J5P7:                  "          
	@echo "                      .:^^!@55&Y5B?^.Y5Y~~~^:.          .7P@@&B!!775P^BG                  "          
	@echo "                        .:!GBP??!:  .#&#57~~:. .   ...::^:^~&&P::~J5P5JY#^                "          
	@echo "                         :^^^: .    .^?YY!^^^^::^^^^::::    J?~.  .:~!!?GY!               "          
	@echo "                                   .:::::.....:::::.                 .^~!5J                "         
	@echo "                                   .:... ..~7~                          ..                 "         
	@echo "                                      ..^!JPP?...                                          "         
	@echo "                                       .7?JJ~^^^^:                                         "         
	@echo "                                  ....:^JY?^~!!!7J.                                        "         
	@echo "                                 .7????JGG5?????~..                                        "         
	@echo "                                 .^~~~~~^^^~.                                              "         
	@sleep 0.01                                                                                                 

sonic4		:
	@clear                                                                                           
	@echo "                                    . .:.                                                   "        
	@echo "                                ...:^^:.                                                    "        
	@echo "                               :^~~~~..                                                     "        
	@echo "                            .:^~~~~^.        ..                                             "        
	@echo "                           :^~~~~~:.      .:^:                                              "        
	@echo "                         .:^~~~~~^....:^^^^^.                                               "        
	@echo "                         :^~~~~~^:^~~~~~~~^.     .                                          "        
	@echo "                      ..J!^~~~~^^~~~~~~~:.     ...         ..:~                             "        
	@echo "                     :.:&BY^~~~~~~~~~~:.....:::..       ^^7PPGG:                            "        
	@echo "                     ..^B5J~~~~~~~~~^^^^~~~~^:.     .~?5#GGGGGG:                            "        
	@echo "                      ..^^~!!!^~~~~~^~~~~~^:::^^!? J#?B@@BGBPY?.                            "        
	@echo "                        .^7@@#Y!~~Y5Y~~~^~!7YPBPP5.!Y~YG@BY.                                "        
	@echo "                        .:~JP#@!7P&&&P!..JGB?!!^::.   :!?GG5.                               "        
	@echo "                         .:^^?@YP&YPB?^:55J~~^^:.    .7YP!!YJJJ.                            "        
	@echo "                           .:7GBP??!:  ^#&#5!~~..     ~7!7?JBGJGG5~~^                       "        
	@echo "                            :^^^: .     ^?YY~^~.   !JJ5PJ??JPGG5J?PP57:                     "        
	@echo "                                         ....:~:. .!5&@&P~:^^^^::::::~:.                    "        
	@echo "                                            ..:~^.:..~PG~:                                  "        
	@echo "                                              .^~^.:~Y7^.:^^.                               "        
	@echo "                                                ...~??!~^^^^?~.                             "        
	@echo "                                              ....:!?JYJ~~7J~:                              "        
	@echo "                                             ^??????JGGP7?!.                                "        
	@echo "                                            .:~~~~~~~^~^                                    "        
	@sleep 0.1

sonic5		:
	@clear                                                                                       
	@echo "                                    .^.                                                      "      
	@echo "                                   .^^^.                                                     "       
	@echo "                                 :^~~^.                                                      "       
	@echo "                              .:^~~~^:                                                       "       
	@echo "                            .:^~~~~~.                                                        "       
	@echo "                           .^~~~~~^.   ...........                                           "       
	@echo "                          :^~~~~~^:.:::~~~~~^:...                                            "       
	@echo "                       .  ^~~~~~^^^~~~~~~~:.    .           ..^^                             "       
	@echo "                      .5Y^^^~~~~~~~~~~~^:.   .::.       .^^JPPG5                             "       
	@echo "                     .:?P&5?^~~~~~~~~~^:::::^^^:.    :~JP#@BPGGY.                            "       
	@echo "                      .:!57~^^~~~~~~^^~~~~~~~:::??! GG?@@@@BP5J7                             "       
	@echo "                       ...^7YY7^~~~~~~~~~~^::JYPBPJ^J?~JP#@GY~:                              "       
	@echo "                         .^Y&@&G~~?BB5!~^:^?P#57^:::    .^^YBG~                              "       
	@echo "                         .:~7JB&^5#&&#P:.^Y?!!^:::.         ..                               "       
	@echo "                          ..:^5&PBG75J^ 7#7!~~~^.                                            "       
	@echo "                           ..^?YP7~7:   !G#J~~~~...                                          "       
	@echo "                             ....        .7~^~^:.   ...^:.^.                                 "       
	@echo "                                          .:^^:....:~!~&Y.PJ!::^7:                           "       
	@echo "                                          :^^ ?PGBP7777J5G^?5^^!G^                           "       
	@echo "                                        .:~^::.~@&BP?77JG&.:^^^!G^                           "       
	@echo "                                         ......^PJ7^^?G!5&^^~5YY5^                           "       
	@echo "                                               ...   ~Y?5B@?.JPY.                            "       
	@echo "                                                     .^?JJ@?.~JJ                             "       
	@echo "                                                    .^?:~?#7.?^                              "       
	@echo "                                                        .:^:.                                "       
	@sleep 0.01

sonic6		:
	@clear
	@echo "                         . .:..                                                               "       
	@echo "                      ..:^^:.                                                                 "       
	@echo "                    :^~~~~..                                                                  "       
	@echo "                 .:^~~~~^.        ..                                                          "       
	@echo "                :^~~~~~^.      .:^:.                                                          "       
	@echo "              ..^~~~~~^....:^^^^^.              ..:!.                                         "       
	@echo "              .^~~~~~^^^~~~~~~~^.     .      ^~7BGPB^                                         "       
	@echo "            .J7^~~~~^^~~~~~~~:.     ...  .~?5#&&YPGG^                                         "       
	@echo "          ...&#5^~~~~~~~~~~^.....:::..~ 7&?G@@#B55Y?:                                         "       
	@echo "          ..:GPJ~~~~~~~~~^^^^~~~~^^.?P&!!J~?G@BPYY7                                           "       
	@echo "            .^^^!!!^~~~~~^~~~~~^::!B#P7:   .:^^~~~^                                           "       
	@echo "             .:!&@&Y!~~Y55!~~^::^5GJ~:                                                        "       
	@echo "             .:^?PB@7~P&&&P7..^!G?~.:::..                                                     "       
	@echo "              .:^^!@P5&Y5B?~.5?~~~~^:.                                                        "       
	@echo "                .:!GBG7?!:  .#BP~~~~:                                                         "       
	@echo "                 :^^^: .    .~7J~^^:...                                                       "       
	@echo "                        .::^^^^:..........    :^^^: .:^Y!                                     "       
	@echo "                       .:^~^...:J!^  ..  .....~?PP57~^^??!.                                   "       
	@echo "                         ..::.~J@&G^!~^:.  ... :GP55~^^^?P.                                   "       
	@echo "                            .!P@@B57777BJ      :?!^.:^^7YP.                                   "       
	@echo "                             ^~!5555?Y#7^            ~J555Y~                                  "       
	@echo "                             .^!JPP^GBY.            .:^^^~G!                                  "       
	@echo "                           .^!!7JY5P7^            :~!!!!!!5!                                  "       
	@echo "                          ~?Y555YY?.             .^??????7.                                   "       
	@echo "                          :^~!!~                                                              "       
	@sleep 0.01

sonic7		:
	@clear
	@echo "	                                         ...                                                  "     
	@echo "                                   ...:^^^^....                                                "     
	@echo "                                .::^~~~~^:.  .:.                                               "     
	@echo "                              .^~~~~~~^: ...^^:.                                               "     
	@echo "                            :^~~~~~~^.:::^^~~^                                                 "     
	@echo "                           :~~~~~~^^:^~~~~~^:.                                                 "     
	@echo "                          .~^~~~~^~~~~~~~~^.              .~~7J.                               "     
	@echo "                         ~J&~.~~~~~~~~~~:..  .::..:... :7J5BGPP:                               "     
	@echo "                        .5#B7^~~~~~~~~^^:^^^~~^:...^~7P#&@#YBBG:   :^^.                        "     
	@echo "                        .!7^^^^~~~~~~^~~~~~~^:.^7Y.Y&?B@@@&P?!^   .!???!                       "     
	@echo "                        ...~P#B7~~~!77!~~~^:^7PGP5~~~:^!5GGP57  .:^^^^~7J~.                    "     
	@echo "                          .^YB@@P^?P&&P?::^J55Y!^.:.      ...^77JY?!^^^^^5Y7.                  "     
	@echo "                          .:~!!&G!##G&GJ ~77!~^^::.         .:~YPPG!.^~75PP5~.                 "     
	@echo "                           ...^G#BPJ7?^ .P#Y!~~~^.         .....7G5~  !?JJ7^P7                 "     
	@echo "                           ..:~77?::^    !JP!~~^:...........   .:^:.    .:^^!?Y.               "     
	@echo "                                      ...::^^^:.  .......                 ..:~?.               "     
	@echo "                                     .^~^^:...                                                 "     
	@echo "                                      .:.....:~?~                                              "     
	@echo "                                         .:^75&&5::.                                           "     
	@echo "                                          :?PGG?777~.                                          "     
	@echo "                                    .^^^^^~YYYYJJJJ55.                                         "     
	@echo "                                   :!J5555P&5YYYYY5!..                                         "     
	@echo "                                   .^~!!!!!!!!!                                                "     
	@sleep 0.01

sonic8		:
	@clear
	@echo "                                          .                                                      "   
	@echo "                                      ...::.                                                     "   
	@echo "                                   .^:^~^.                                                       "   
	@echo "                                ..^~~~^^.                                                        "   
	@echo "                              .:^~~~~~:.       ...                                               "   
	@echo "                             .:~~~~~~..  ....:^:.                                                "   
	@echo "                            .:~~~~~^:.:::^~~~^:.                                                 "   
	@echo "                            :^~~~~^^^~~~~~~~^.     ..                                            "   
	@echo "                        ..^B?~~~~~~~~~~~~^^.   ...:.         :!~7J                               "   
	@echo "                        :.^&#5^~~~~~~~~~^:::::^^^:.     . :?J5PPGP.                              "   
	@echo "                        ..^P7~^^~~~~~~^^~~~~~~~:..  . ^!7P#&GG&BBP.                              "   
	@echo "                          ..^!5Y?^~~~~~~~~~~^:.^!?J55 P&7#@@G5J7!^                               "   
	@echo "                           .^?&@&B~~7BBG!~^:7YPPGGJ??.^^:7YB&5^                                  "   
	@echo "                           .:^7?P@~J#&&&G~.:J55~^:::.     .:?JJ.^77^ .                           "   
	@echo "                            ..:^J&GBB7YY^.~#?!~~~~..      .~^::^~!G5YJ~^^                        "   
	@echo "                             ..^7YP?^7^   ^PB5~~~~.    :77?Y7~^^!?PY?^7??7~                      "   
	@echo "                               ....        .!!:~^:...  :?5PPP7..:^^:.....^:.                     "   
	@echo "                                             .:^:.... .. ^7G!^                                   "   
	@echo "                                            .:~^:.:.. YG5~:^.                                    "   
	@echo "                                             .^:::^:: P@@GJ.:.                                   "   
	@echo "                                                    :5GBPJ7!!!!.                                 "   
	@echo "                                               ....:^~7JYYJ755Y.                                 "   
	@echo "                                             .^7???JJJGBJGBP7^                                   "   
	@echo "                                             .!7JYYYYYYYY^..                                     "   
	@sleep 0.01                                                                                                
                                                                                                                       

.PHONY		: re all bonus clean fclean libft
