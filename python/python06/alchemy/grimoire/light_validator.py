"""Validation of ingredients used by light magic."""


def validate_ingredients(ingredients: str) -> str:
    """Return the ingredients followed by VALID or INVALID."""
    from .light_spellbook import light_spell_allowed_ingredients

    allowed = light_spell_allowed_ingredients()
    lowered = ingredients.lower()
    for item in allowed:
        if item in lowered:
            return f"{ingredients} - VALID"
    return f"{ingredients} - INVALID"
