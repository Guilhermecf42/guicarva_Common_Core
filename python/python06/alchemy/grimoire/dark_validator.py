"""Validation of ingredients used by dark magic."""
from .dark_spellbook import dark_spell_allowed_ingredients


def validate_dark_ingredients(ingredients: str) -> str:
    """Return the ingredients followed by VALID or INVALID."""
    allowed = dark_spell_allowed_ingredients()
    lowered = ingredients.lower()
    for item in allowed:
        if item in lowered:
            return f"{ingredients} - VALID"
    return f"{ingredients} - INVALID"
