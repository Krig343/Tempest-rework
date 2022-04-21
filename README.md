# Ajouts à faire pour compiler

1) Il faut ajouter la lib SDL au même niveau que projet/ et le CMakeList.
2) Il faut créer un dossier build au même niveau que projet/ et le CMakeList

# Ajouts pour le projet

* Une classe mechanics pour gérer les évènements concernants plusieurs classes.
* Une classe spike qui est la trace laissée par les spikers.
* Il faut également trouver un moyen de déterminer des paliers de profondeur pour les spikes et le nombre de points données par un fuseball.
* Un maximum de huit missiles peuvent avoir été tirés. Après il faudra attendre qu'ils se soient crashés pour tirer à nouveau.