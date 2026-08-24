"""Recipes mixing elements and potions to transmute matter."""
from alchemy.potions import strength_potion
from elements import create_fire

from ..elements import create_air


def lead_to_gold() -> str:
    """Return the recipe turning lead into gold."""
    return (
        f"Recipe transmuting Lead to Gold: brew '{create_air()}' "
        f"and '{strength_potion()}' mixed with '{create_fire()}'"
    )
