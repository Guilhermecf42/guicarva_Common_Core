"""Spellbook recording the spells of light magic."""
from .light_validator import validate_ingredients


def light_spell_allowed_ingredients() -> list[str]:
    """Return the ingredients allowed for light magic."""
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:
    """Record or reject a light spell depending on its ingredients."""
    checked = validate_ingredients(ingredients)
    if checked.endswith("VALID") and not checked.endswith("INVALID"):
        return f"Spell recorded: {spell_name} ({checked})"
    return f"Spell rejected: {spell_name} ({checked})"
