"""Spellbook recording the spells of dark magic."""
from .dark_validator import validate_dark_ingredients


def dark_spell_allowed_ingredients() -> list[str]:
    """Return the ingredients allowed for dark magic."""
    return ["bats", "frogs", "arsenic", "eyeball"]


def dark_spell_record(spell_name: str, ingredients: str) -> str:
    """Record or reject a dark spell depending on its ingredients."""
    checked = validate_dark_ingredients(ingredients)
    if checked.endswith("VALID") and not checked.endswith("INVALID"):
        return f"Spell recorded: {spell_name} ({checked})"
    return f"Spell rejected: {spell_name} ({checked})"
