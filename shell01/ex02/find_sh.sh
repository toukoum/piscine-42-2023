find . -type f -name "*.sh" -exec basename --suffix=.sh {} +


# pour selectionner chaque fichier 
# L'option --suffix=.sh signifie "enlever le suffixe .sh du nom du fichier
# + option pour executer basenane aussi peu de fois que possible
