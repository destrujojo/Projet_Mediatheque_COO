# Compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -Wextra -I./include -I./Ressources -I./Livres -I./Revues -I./CD -I./VHS -I./DVD -I./RessourcesNumeriques

# Nom de l'exécutable
TARGET = mon_programme

# Fichiers sources
SRCS = main.cpp \
       Livres/Livres.cpp \
       Revues/Revues.cpp \
       CD/CD.cpp \
	   VHS/VHS.cpp \
	   DVD/DVD.cpp \
	   RessourcesNumeriques/RessourcesNumeriques.cpp \
       Ressources/Ressources.cpp

# Fichiers objets (remplace les .cpp par .o)
OBJS = $(SRCS:.cpp=.o)

# Règle par défaut pour construire l'exécutable
all: $(TARGET)

# Règle pour l'exécutable
$(TARGET): $(OBJS)
	$(CXX) -o $@ $^

# Règle pour générer les fichiers objets à partir des fichiers sources
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers générés
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
